/*
 ******************************************************************************
 * @file           : DS1307_Prv.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : DS1307 PRIVATE FILE
 * @Date           : Nov 10, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef DS1307_INC_DS1307_PRV_H_
#define DS1307_INC_DS1307_PRV_H_

/*==============================================================================================================================================
 * PRIVATE DEFINES
 *==============================================================================================================================================*/


#define DEVICE_ADDRESS 0b1101000

#define WORD_ADDRESS	0U

#define DS1307_12_24_SELECTION_BIT	6U
#define DS1307_AM_PM_SELECTION_BIT  5U

#define DS1307_WRITE_ARR_SIZE  		8U
#define DS1307_READ_ARR_SIZE  		7U

#define DS1307_HOUR_REG_MASK		0x1F

typedef enum
{
	DS1307_SEC = 0  ,
	DS1307_MIN 		,
	DS1307_HOUR		,
	DS1307_DAY		,
	DS1307_DATE		,
	DS1307_MONTH	,
	DS1307_YEAR
}DS1307_REGISTER_t;

/*==============================================================================================================================================
 * PRIVATE FUNCTIONS
 *==============================================================================================================================================*/


/**
 * @fn 		: _u8SingleBinaryToBCD(uint8_t)
 * @brief 	: THIS FUNCTION CONVERTS FROM BINARY TO BCD FOR A SINGLE DECIMAL NUMBER
 *
 * @param 	: Copy_u8Decimal => NUMBER REQUIRED TO CONVERt TO BCD FORMAT
 * @return	: NUMBER IN BCD FORMAT
 * @note	: PRIVATE FUNCTION FOR PROVIDER USE ONLY
 */
static uint8_t _u8SingleBinaryToBCD( uint8_t Copy_u8Decimal ) ;

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
static ERRORS_t _eAllBinaryToBCD( DS1307_Config_t * DS1307_Config , uint8_t * Copy_pu8BCDData , uint8_t * Copy_u8Length );

/**
 * @fn 		: __u8SingleBCDToBinary(uint8_t)
 * @brief 	: THIS FUNCTION CONVERTS FROM BCD TO BINARY FOR A SINGLE DECIMAL NUMBER
 *
 * @param 	: Copy_u8Decimal => NUMBER REQUIRED TO CONVERT TO BINARY FORMAT
 * @return	: NUMBER IN BINARY FORMAT
 * @note	: PRIVATE FUNCTION FOR PROVIDER USE ONLY
 */
static uint8_t _u8SingleBCDToBinary( uint8_t Copy_u8BCD ) ;

/**
 * @fn 			: _eAllBCDToBinary(DS1307_Config_t*, uint8_t*)
 * @brief 		: THIS FUNCITON CONVERTS ALL ARRAY READ FROM RTC MODULE IN BCD FORMAT INTO BINARY FORMAT IN FORM OF DS1307 CONFIG STRUCT
 *
 * @param[out]	: DS1307_Data 	=> A POINTER TO STRUCT HOLDING DATA IN BINARY FORMAT AS RETURN
 * @param[in] 	: Copy_pu8Data  => POINTER HOLDING DATA READ FROM RTC MODULE IN BCD FORMAT
 * @return		: ERROR STATUS
 * @note		: PRIVATE FUNCITON FOR PROVIDER USE ONLY
 */
static ERRORS_t _eAllBCDToBinary( DS1307_Config_t * DS1307_Data , uint8_t * Copy_pu8Data ) ;

#endif /* DS1307_INC_DS1307_PRV_H_ */
