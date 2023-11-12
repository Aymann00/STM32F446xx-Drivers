/*
 ******************************************************************************
 * @file           : EEPROM_Interface.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : Nov 12, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 ******************************************************************************
 */
#ifndef INC_EEPROM_INTERFACE_H_
#define INC_EEPROM_INTERFACE_H_

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
 * PROTOTYPES SECTION
 * ====================================================================== */

/**
 * @fn 		: HEEPROM_eInit(I2C_Config_t*)
 * @brief 	: THIS FUNCTION INITIALIZES EEPROM TO WORK VIA I2C INITIALIZATION
 *
 * @param 	: I2CConfig		=> POINTER TO STRUCTURE HOLDING I2C CONFIGURATION INFO
 * @return	: ERROR STATUS
 */
ERRORS_t HEEPROM_eInit( I2C_Config_t * I2CConfig ) ;


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
ERRORS_t HEEPROM_eWriteData( uint16_t Copy_u16MemAddress , uint8_t * Copy_pu8DataBuffer , uint8_t Copy_u8BufferSize ) ;

/**
 * @fn 		: HEEPROM_vWriteCycleDelay(void)
 * @brief 	: PROVIDES DELAY BASED ON WRITE CYCLE TIME TAKEN BY EEPROM
 *
 */
void HEEPROM_vWriteCycleDelay( void ) ;

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
ERRORS_t HEEPROM_eReadData( uint16_t Copy_u16MemAddress , uint8_t * Copy_pu8ReadDataBuffer , uint8_t Copy_u8BufferSize ) ;
#endif /* INC_EEPROM_INTERFACE_H_ */
