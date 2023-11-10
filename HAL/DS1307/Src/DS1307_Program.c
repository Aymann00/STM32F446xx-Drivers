/*
 ******************************************************************************
 * @file           : DS1307_Program.c
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : DS1307 MAIN PROGRAM
 * @Date           : Nov 10, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */

/*==============================================================================================================================================
 * INCLUDES SECTION
 *==============================================================================================================================================*/

#include <stdint.h>

#include "../../../LIB/ErrType.h"
#include "../../../LIB/STM32F446xx.h"

#include "../../../MCAL/I2C/Inc/I2C_Interface.h"

#include "../Inc/DS1307_Config.h"
#include "../Inc/DS1307_Interface.h"
#include "../Inc/DS1307_Prv.h"

/*==============================================================================================================================================
 * GLOBAL SECTION
 *==============================================================================================================================================*/
I2C_Config_t * I2CCONFIG  ;

/*==============================================================================================================================================
 * IMPLEMENTATION SECTION
 *==============================================================================================================================================*/

/**
 * @fn 		: HDS1307_eInit
 * @brief 	: THIS FUNCTION INITIALIZES DS1307 MODULE THROUGH I2C COMMUNICATION
 * @param 	: Copy_I2CConfig => A POINTER TO STRUCTURE HOLDING I2C CONFIGURATION INFO
 * @return	: ERROR STATUS
 */
ERRORS_t HDS1307_eInit( I2C_Config_t * Copy_pI2CConfig )
{
	ERRORS_t Local_ErrorStatus = OK ;

	/* INITIALIZE I2C CONFIGURATION GLOBALLY */
	I2CCONFIG = Copy_pI2CConfig ;

	/* INITIALIZE I2C PERIPHERAL */
	Local_ErrorStatus = MI2C_eInit( Copy_pI2CConfig );

	return Local_ErrorStatus ;
}

/**
 * @fn 		: HDS1307_eWriteData
 * @brief 	: THIS FUNCTION WRITES DATA INTO RTC MODULE TO CONFIGURE DATE TIME CHARACTARISTICS
 * @param 	: Copy_pDS1307Config => A POINTER TO STRUCTURE HOLDING DS1307 CONFIGURATION INFO
 * @return	: ERROR STATUS
 */
ERRORS_t HDS1307_eWriteData( DS1307_Config_t * Copy_pDS1307Config )
{
	ERRORS_t Local_ErrorStatus = OK ;

	/* Variable Holding Array of Data to Send to DS1307 Module */
	uint8_t Local_u8Data [ DS1307_WRITE_ARR_SIZE ] = { 0 } ;

	/* Length of Data to Send to DS1307 Module */
	uint8_t Local_u8DataLength ;

	/* Converting DS1307 Config Structure into Array of Data */
	Local_ErrorStatus = _eAllBinaryToBCD( Copy_pDS1307Config, Local_u8Data, &Local_u8DataLength ) ;

	if( Local_ErrorStatus != NOK )
	{
		/* RIGHT VALUES */
		/* Send Start Condition , DS1307 Address with Write */
		MI2C_eSendStartCondition( I2CCONFIG , DEVICE_ADDRESS , I2C_RW_BIT_WRITE ) ;

		/* Send Array of Time / Date Configuration to DS1307 Module */
		MI2C_eMasterWriteData( I2CCONFIG, Local_u8Data, Local_u8DataLength) ;

		/* Send Stop Condition */
		MI2C_vSendStopCondition( I2CCONFIG);
	}

	return Local_ErrorStatus ;
}

/**
 * @fn 		: HDS1307_eReadData
 * @brief 	: THIS FUNCTION READS DATA FROM DS1307 RTC MODULE IN TERMS OF DS1307 STRUCTURE
 * @param 	: Copy_pDS1307_DataToRead => A POINTER TO STRUCTURE WILL HOLD DATA READ FROM RTC MODULE
 * @return	: ERROR STATUS
 */
ERRORS_t HDS1307_eReadData( DS1307_Config_t * Copy_pDS1307_DataToRead )
{
	ERRORS_t Local_ErrorStatus = OK ;

	/* Variable Holding Word Address to Send Before Reading From RTC Module */
	uint8_t Local_u8WordAddress = WORD_ADDRESS ;

	/* Array Holding Data Read From DS1307 Module */
	uint8_t Local_u8ReadData[ DS1307_READ_ARR_SIZE ] = { 0 } ;

	/* START THE PROCEDURE OF READING */

	/* Send Start Condition , DS1307 Address with Write */
	MI2C_eSendStartCondition( I2CCONFIG, DEVICE_ADDRESS , I2C_RW_BIT_WRITE ) ;

	/* Send Word Address Byte to the Module */
	MI2C_eMasterWriteData( I2CCONFIG, &Local_u8WordAddress, 1 ) ;

	/* Send A Repeated Start to Change Direction to Read with the Same Address */
	MI2C_eSendRepeatedStart( I2CCONFIG, DEVICE_ADDRESS ,  I2C_RW_BIT_READ ) ;

	/* Read Data From DS1307 Module */
	MI2C_eReadData( I2CCONFIG, Local_u8ReadData, DS1307_READ_ARR_SIZE ) ;

	/* Send Stop Condition */
	MI2C_vSendStopCondition( I2CCONFIG ) ;

	/* Convert Array of Data Read From DS1307 Module into Data in terms of DS1307 Structure */
	Local_ErrorStatus = _eAllBCDToBinary( Copy_pDS1307_DataToRead , Local_u8ReadData ) ;

	return Local_ErrorStatus ;
}

/*==============================================================================================================================================
 * PRIVATE FUNCTIONS SECTION
 *==============================================================================================================================================*/

/**
 * @fn 			: _eAllBinaryToBCD(DS1307_Config_t* , uint8_t* , uint8_t*)
 * @brief 		: THIS FUNCTION TRANSFERS THE WHOLE DS1307 CONFIG STRUCTURE INTO AN ARRAY TO SEND DIRECTLY TO DS1307 MODULE
 *
 * @param[in] 	: DS1307_Config		=> A POINTER TO STRUCTURE HOLDING DS1307 CONFIGURATION INFO TO SEND TO RTC MODULE
 * @param[out] 	: Copy_pu8BCDData	=> RETURN FOR USER ARRAY HOLDING DATA EXTRACTED FROM CONFIG STRUCTURE IN FORM OF BCD TO SEND TO RTC MODULE
 * @param[out]  : Copy_u8Length		=> RETURN THE SIZE OF ARRAY TO SEND TO THE RTC MODULE
 * @return		: ERROR STATUS
 * @note	: PRIVATE FUNCTION FOR PROVIDER USE ONLY
 */
static ERRORS_t _eAllBinaryToBCD( DS1307_Config_t * DS1307_Config , uint8_t * Copy_pu8BCDData , uint8_t * Copy_u8Length )
{
	ERRORS_t Local_ErrorStatus = OK ;

	/* Variable to Return Length of Array */
	uint8_t Local_u8Counter = 0 ;

	/* SETTING WORD ADDRESS */
	Copy_pu8BCDData[ Local_u8Counter ] = WORD_ADDRESS ;

	Local_u8Counter++ ;

	/* SETTING SECONDS */
	if( ( DS1307_Config->Seconds ) < 0 || ( DS1307_Config->Seconds > 59 ) )
	{
		/* WRONG */
		return NOK ;
	}
	else
	{
		/* RIGHT */
		Copy_pu8BCDData[ Local_u8Counter ] = _u8SingleBinaryToBCD( DS1307_Config->Seconds ) ;
	}
	Local_u8Counter++;

	/* SETTING MINUTES */
	if( ( DS1307_Config->Minutes ) < 0 || ( DS1307_Config->Minutes > 59 ) )
	{
		/* WRONG */
		return NOK ;
	}
	else
	{
		/* RIGHT */
		Copy_pu8BCDData[ Local_u8Counter ] = _u8SingleBinaryToBCD( DS1307_Config->Minutes ) ;
	}
	Local_u8Counter++;

	/* SETTING HOURS */
	if( DS1307_HOUR_FORMAT == DS1307_HOUR_24FORMAT )
	{
		/* 24 HOUR FORMAT*/
		if( ( DS1307_Config->Hours < 0 ) || ( DS1307_Config->Hours > 23 ) )
		{
			/* WRONG */
			return NOK ;
		}
		else
		{
			/* RIGHT */
			Copy_pu8BCDData[ Local_u8Counter ] = _u8SingleBinaryToBCD( DS1307_Config->Hours ) ;
		}

	}
	else if( DS1307_HOUR_FORMAT == DS1307_HOUR_12FORMAT )
	{
		/* 12 HOUR FORMAT */
		if( (DS1307_Config->Hours < 1) || (DS1307_Config->Hours > 12) )
		{
			/* WRONG */
			return NOK ;
		}
		else
		{
			/* RIGHT */
			uint8_t Local_u8Hour = 0 ;

			Local_u8Hour = _u8SingleBinaryToBCD( DS1307_Config->Hours ) ;

			/* CHOOSE 12 HOUR FORMAT */
			Local_u8Hour |= ( 1 << DS1307_12_24_SELECTION_BIT ) ;

			if( DS1307_Config->_12Format == DS1307_12FORMAT_AM )
			{
				/* AM */
				Local_u8Hour &= ( ~ ( 1 << DS1307_AM_PM_SELECTION_BIT ) ) ;
			}
			else if( DS1307_Config->_12Format == DS1307_12FORMAT_PM )
			{
				/* PM */
				Local_u8Hour |= ( 1 << DS1307_AM_PM_SELECTION_BIT ) ;
			}
			else
			{
				return NOK ;
			}

			Copy_pu8BCDData[ Local_u8Counter ] = Local_u8Hour ;
		}
	}
	Local_u8Counter++;

	/* SETTING DAY */
	if( ( DS1307_Config->Day < DS1307_DAY_SUNDAY ) || ( DS1307_Config->Day > DS1307_DAY_SATURDAY ) )
	{
		return NOK ;
	}
	else
	{
		/* RIGHT */
		Copy_pu8BCDData[ Local_u8Counter ] = _u8SingleBinaryToBCD(DS1307_Config->Day);
	}
	Local_u8Counter++ ;

	/* SETTING DATE */
	if( (DS1307_Config->Date < 1) || (DS1307_Config->Date > 31) )
	{
		return NOK ;
	}
	else
	{
		Copy_pu8BCDData[ Local_u8Counter ] = _u8SingleBinaryToBCD( DS1307_Config->Date ) ;
	}
	Local_u8Counter++ ;

	/* SETTING MONTH */
	if( (DS1307_Config->Month < 1) || (DS1307_Config->Month > 12) )
	{
		return NOK ;
	}
	else
	{
		Copy_pu8BCDData[ Local_u8Counter ] = _u8SingleBinaryToBCD( DS1307_Config->Month ) ;
	}
	Local_u8Counter++ ;

	/* SETTING YEAR */
	Copy_pu8BCDData[ Local_u8Counter ] = _u8SingleBinaryToBCD( DS1307_Config->Year ) ;

	Local_u8Counter++ ;

	/* Return Array length */
	*Copy_u8Length = Local_u8Counter ;

	return Local_ErrorStatus ;
}

/**
 * @fn 		: _u8SingleBinaryToBCD(uint8_t)
 * @brief 	: THIS FUNCTION CONVERTS FROM BINARY TO BCD FOR A SINGLE DECIMAL NUMBER
 *
 * @param 	: Copy_u8Decimal => NUMBER REQUIRED TO CONVERt TO BCD FORMAT
 * @return	: NUMBER IN BCD FORMAT
 * @note	: PRIVATE FUNCTION FOR PROVIDER USE ONLY
 */
static uint8_t _u8SingleBinaryToBCD( uint8_t Copy_u8Decimal )
{
	uint8_t Local_u8BCD = 0  , Local_u8Temp = 0 , Local_u8Counter = 0;

	while( Copy_u8Decimal != 0 )
	{
		Local_u8Temp = Copy_u8Decimal % 10 ;

		Copy_u8Decimal = Copy_u8Decimal / 10 ;

		Local_u8BCD |= ( Local_u8Temp << Local_u8Counter ) ;

		Local_u8Counter += 4 ;
	}

	return Local_u8BCD ;
}

/**
 * @fn 			: _eAllBCDToBinary(DS1307_Config_t*, uint8_t*)
 * @brief 		: THIS FUNCITON CONVERTS ALL ARRAY READ FROM RTC MODULE IN BCD FORMAT INTO BINARY FORMAT IN FORM OF DS1307 CONFIG STRUCT
 *
 * @param[out]	: DS1307_Data 	=> A POINTER TO STRUCT HOLDING DATA IN BINARY FORMAT AS RETURN
 * @param[in] 	: Copy_pu8Data  => POINTER HOLDING DATA READ FROM RTC MODULE IN BCD FORMAT
 * @return		: ERROR STATUS
 * @note		: PRIVATE FUNCITON FOR PROVIDER USE ONLY
 */
static ERRORS_t _eAllBCDToBinary( DS1307_Config_t * DS1307_Data , uint8_t * Copy_pu8Data )
{
	ERRORS_t Local_ErrorStatus = OK ;

	/* EXTRACTING SECONDS */
	DS1307_Data->Seconds = _u8SingleBCDToBinary(Copy_pu8Data[DS1307_SEC]) ;

	/* EXTRACTING MINUTES */
	DS1307_Data->Minutes = _u8SingleBCDToBinary(Copy_pu8Data[DS1307_MIN]) ;

	/* EXTRACTING HOURS */
	if( DS1307_HOUR_FORMAT == DS1307_HOUR_24FORMAT )
	{
		/* IF HOURS IN 24 HOUR FORMAT */
		DS1307_Data->Hours	= _u8SingleBCDToBinary(Copy_pu8Data[DS1307_HOUR]) ;
	}
	else if( DS1307_HOUR_FORMAT == DS1307_HOUR_12FORMAT  )
	{
		/* IF HOURS IN 12 HOUR FORMAT */

		/* Read Hour Only without AM/PM Bit & without 12Format / 24Format Bit */
		uint8_t Local_u8Hour =  Copy_pu8Data[ DS1307_HOUR ] & DS1307_HOUR_REG_MASK ;

		DS1307_Data->Hours = _u8SingleBCDToBinary(Local_u8Hour) ;

		/* EXTRACTING AM / PM INFO */
		if( ( Copy_pu8Data[ DS1307_HOUR ] >> DS1307_AM_PM_SELECTION_BIT ) & 1U )
		{
			/* PM */
			DS1307_Data->_12Format = DS1307_12FORMAT_PM ;
		}
		else if( !( ( Copy_pu8Data[ DS1307_HOUR ] >> DS1307_AM_PM_SELECTION_BIT ) & 1U  ) )
		{
			/* AM */
			DS1307_Data->_12Format = DS1307_12FORMAT_AM ;
		}
		else
		{
			return NOK ;
		}
	}
	else
	{
		return NOK ;
	}

	/* EXTRACTING DAY */
	DS1307_Data->Day = _u8SingleBCDToBinary( Copy_pu8Data[ DS1307_DAY ] ) ;

	/* EXTRACTING DATE */
	DS1307_Data->Date = _u8SingleBCDToBinary( Copy_pu8Data[ DS1307_DATE ] ) ;

	/* EXTRACTING MONTH */
	DS1307_Data->Month = _u8SingleBCDToBinary( Copy_pu8Data[ DS1307_MONTH ] ) ;

	/* EXTRACTING YEAR */
	DS1307_Data->Year = _u8SingleBCDToBinary( Copy_pu8Data[ DS1307_YEAR ] ) ;

	return Local_ErrorStatus ;
}

/**
 * @fn 		: __u8SingleBCDToBinary(uint8_t)
 * @brief 	: THIS FUNCTION CONVERTS FROM BCD TO BINARY FOR A SINGLE DECIMAL NUMBER
 *
 * @param 	: Copy_u8Decimal => NUMBER REQUIRED TO CONVERT TO BINARY FORMAT
 * @return	: NUMBER IN BINARY FORMAT
 * @note	: PRIVATE FUNCTION FOR PROVIDER USE ONLY
 */
static uint8_t _u8SingleBCDToBinary( uint8_t Copy_u8BCD )
{
	uint8_t Local_u8Binary = 0 ;

	Local_u8Binary += ( Copy_u8BCD & 0x0F ) * 1 ;

	Local_u8Binary += ( ( Copy_u8BCD & 0xF0 ) >> 4 ) * 10 ;

	return Local_u8Binary ;
}
