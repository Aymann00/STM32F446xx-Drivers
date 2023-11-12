/*
 ******************************************************************************
 * @file           : EEPROM_Program.c
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : EEPROM MAIN PROGRAM FILE
 * @Date           : Nov 12, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 ******************************************************************************
 */

/* ======================================================================
 * PLEASE READ THE FOLLOWING SPECIFICATIONS
 * ====================================================================== */
/**
 * 	 @CHIP_NAME 		: AT24C08
 *   @SIZE	   		    : 1 KB -> 1024 BYTE  -> 8192 BIT
 *   @SPECIFICATIONS    : 64 PAGES EACH PAGE 16 BYTES
 *   @ADDRESS_WORD	    : 10-BIT ADDRESS
 *   @ADDRESS_LIMIT     : 0 -> 1023
 *   @MEMORY_BLOCKS 	: 4 BLOCKS EACH 256 BYTE
 */


/* ======================================================================
 * INCLUDES SECTION
 * ====================================================================== */


#include <stdint.h>

#include "../../../LIB/ErrType.h"
#include "../../../LIB/STM32F446xx.h"

#include "../../../MCAL/I2C/Inc/I2C_Interface.h"
#include "../../../MCAL/SYSTICK/Inc/SYSTICK_Interface.h"

#include "../Inc/EEPROM_Interface.h"
#include "../Inc/EEPROM_Config.h"
#include "../Inc/EEPROM_Prv.h"

/* ======================================================================
 * GLOBALS SECTION
 * ====================================================================== */
I2C_Config_t * I2C_CONFIG ;

/* ======================================================================
 * IMPLEMENTATION SECTION
 * ====================================================================== */

/**
 * @fn 		: HEEPROM_eInit(I2C_Config_t*)
 * @brief 	: THIS FUNCTION INITIALIZES EEPROM TO WORK VIA I2C INITIALIZATION
 *
 * @param 	: I2CConfig		=> POINTER TO STRUCTURE HOLDING I2C CONFIGURATION INFO
 * @return	: ERROR STATUS
 */
ERRORS_t HEEPROM_eInit( I2C_Config_t * I2CConfig )
{
	ERRORS_t Local_ErrorStatus = OK ;

	/* INITIALIZE I2C */
	Local_ErrorStatus = MI2C_eInit(I2CConfig);

	/* INITIALIZE POINTER TO STRUCT GLOBALLY */
	I2C_CONFIG = I2CConfig ;

	return Local_ErrorStatus ;
}

/**
 * @fn 		: HEEPROM_eWriteData(uint16_t, uint8_t*, uint8_t)
 * @brief 	: THIS FUNCTION TAKES MEMORY ADDRESS & DATA TO WRITE IT IN THIS ADDRESS
 *
 * @param 	: Copy_u16MemAddress	=> MEMORY ADDRESS TO START WRITTING AT ,
 * 										CHECK VALID MEMORY ADDRESSES @ADDRESS_LIMIT
 * @param 	: Copy_pu8DataBuffer	=> BUFFER HOLDING DATA TO WRITE STARTING FROM PROVIDED MEM ADDRESS
 * @param 	: Copy_u8BufferSize		=> SIZE OF DATA BUFFER
 * @return	: ERROR STATUS
 * @note	: IF MEMORY ADDRESS PROVIDED IS A START OF A PAGE ( MULTIPLIES OF 16 ) FOR EX ( 0 , 0X10 , 0X20 , 0X30 , ... )
 * 								-> YOU CAN WRITE UP TO 16 BYTE IN THE SAME PAGE
 * 			  IF YOU PROVIDED MEMORY ADDRESS NOT AT START OF A PAGE & REQUESTED TO WRITE MORE THAN PAGE CAN HANDLE
 * 			  PAGE WILL ROLL OVER AND START FROM THE BEGINING OF THE PAGE
 * 			 -SO FOR NOW KEEP MAX SIZE TO WRITE 16 BYTES & PROVIDE ADDRESS MULTIPILES OF 16 ONLY ( PAGE START ADDRESS )
  NOTE 		: CAN SUPPORT MORE THAN 16 BYTES IN LATER VERSIONS
 */
ERRORS_t HEEPROM_eWriteData( uint16_t Copy_u16MemAddress , uint8_t * Copy_pu8DataBuffer , uint8_t Copy_u8BufferSize )
{
	ERRORS_t Local_ErrorStatus = OK ;

	uint8_t Local_u8LoopCounter ;

	uint8_t Local_u8MemBlock = (uint8_t)( Copy_u16MemAddress >> 8 ) ;

	uint8_t Local_u8DeviceAddress = (uint8_t)( ( EEPROM_DEVICE_ADDRESS << 3 ) | ( EEPROM_MEM_DEVICE << 2 ) | ( Local_u8MemBlock )  ) ;

	/* SEND START CONDITION , DEVICE ADDRESS( 1010 + A2 + BIT9 + BIT8 ) WITH WRITE */
	Local_ErrorStatus = MI2C_eSendStartCondition( I2C_CONFIG , Local_u8DeviceAddress , I2C_RW_BIT_WRITE ) ;

	/*CHECK*/
	if( Local_ErrorStatus != OK )
	{
		return NOK ;
	}

	/* SEND WORD ADDRESS */
	Local_ErrorStatus = MI2C_eMasterWriteData( I2C_CONFIG , (uint8_t*)&Copy_u16MemAddress , 1 ) ;

	/*CHECK*/
	if( Local_ErrorStatus != OK )
	{
		return NOK ;
	}


	/* DELAY 1us */
	SYSTICK_Delayus( 1u ) ;

	/* SEND DATA BYTES */
	for( Local_u8LoopCounter = 0 ; Local_u8LoopCounter < Copy_u8BufferSize ; Local_u8LoopCounter++ )
	{
		/* SEND BYTE BY BYTE */
		Local_ErrorStatus = MI2C_eMasterWriteData(I2C_CONFIG, &Copy_pu8DataBuffer[ Local_u8LoopCounter ] , 1 ) ;

		/*CHECK*/
		if( Local_ErrorStatus != OK )
		{
			return NOK ;
		}

		/* DELAY 200us BETWEEN EACH DATA BYTE SENT */
		SYSTICK_Delayus( 200u ) ;
	}

	/* SEND STOP CONDITION */

	MI2C_vSendStopCondition(I2C_CONFIG);

	return Local_ErrorStatus ;
}


/**
 * @fn 		: HEEPROM_vWriteCycleDelay(void)
 * @brief 	: PROVIDES DELAY BASED ON WRITE CYCLE TIME TAKEN BY EEPROM
 *
 */
void HEEPROM_vWriteCycleDelay( void )
{
	SYSTICK_Delayms( EEPROM_WRITE_CYCLE_TIME ) ;
}


/**
 * @fn 			: HEEPROM_eReadData(uint16_t, uint8_t*, uint8_t)
 * @brief 		: THIS FUNCTION READ DATA BYTES STARTING FROM A SPECIFIC ADDRESS
 *
 * @param[in]	: Copy_u16MemAddress	=> MEMORY ADDRESS TO START WRITTING AT ,
 * 										CHECK VALID MEMORY ADDRESSES @ADDRESS_LIMIT
 * @param[out] 	: Copy_pu8ReadDataBuffer=> BUFFER TO HOLD DATA READ STARTING FROM PROVIDED MEM ADDRESS
 * @param[in]	: Copy_u8BufferSize		=> SIZE OF DATA BUFFER
 * @return		: ERROR STATUS
 */
ERRORS_t HEEPROM_eReadData( uint16_t Copy_u16MemAddress , uint8_t * Copy_pu8ReadDataBuffer , uint8_t Copy_u8BufferSize )
{
	ERRORS_t Local_ErrorStatus = OK ;

	/* GET BIT9 & BIT8 OF MEMORY ADDRESS */
	uint8_t Local_u8MemBlock = (uint8_t)( Copy_u16MemAddress >> 8 ) ;

	/* GET DEVICE ADDRES TO SEND */
	uint8_t Local_u8DeviceAddress = (uint8_t)( ( EEPROM_DEVICE_ADDRESS << 3 ) | ( EEPROM_MEM_DEVICE << 2 ) | ( Local_u8MemBlock )  ) ;

	/* SEND START CONDITION , DEVICE ADDRESS( 1010 + A2 + BIT9 + BIT8 ) WITH WRITE */
	Local_ErrorStatus = MI2C_eSendStartCondition( I2C_CONFIG , Local_u8DeviceAddress , I2C_RW_BIT_WRITE ) ;

	/*CHECK*/
	if( Local_ErrorStatus != OK )
	{
		return NOK ;
	}

	/* SEND WORD ADDRESS */
	Local_ErrorStatus = MI2C_eMasterWriteData( I2C_CONFIG , (uint8_t*)&Copy_u16MemAddress , 1 ) ;

	/*CHECK*/
	if( Local_ErrorStatus != OK )
	{
		return NOK ;
	}

	/* SEND REPEATED START , DEVICE ADDRESS ( 1010 + A2 + BIT9 + BIT8 ) WITH READ */
	Local_ErrorStatus = MI2C_eSendRepeatedStart(I2C_CONFIG, Local_u8DeviceAddress , I2C_RW_BIT_READ ) ;

	if( Local_ErrorStatus != OK )
	{
		return NOK ;
	}

	/* READ DATA BYTES AND STORE THEM IN BUFFER FOR USER RETURN */
	Local_ErrorStatus = MI2C_eReadData(I2C_CONFIG, Copy_pu8ReadDataBuffer, Copy_u8BufferSize) ;

	/* CHECK */
	if( Local_ErrorStatus != OK )
	{
		return NOK ;
	}

	/* SEND STOP CONDITION */
	MI2C_vSendStopCondition(I2C_CONFIG);

	return Local_ErrorStatus ;
}
