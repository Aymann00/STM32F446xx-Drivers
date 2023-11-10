/*
 ******************************************************************************
 * @file           : DS1307_Interface.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : DS1307 ( RTC ) INTERFACE FILE
 * @Date           : Nov 10, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef DS1307_INC_DS1307_INTERFACE_H_
#define DS1307_INC_DS1307_INTERFACE_H_

/*==============================================================================================================================================
 * OPTION ENUMS
 *==============================================================================================================================================*/

/**
 * @enum	: @DS1307_12FORMAT_t
 * @brief 	: HOLDS AM / PM VALUE IF 12 HOUR FORMAT IS USED
 *
 */
typedef enum
{
	DS1307_12FORMAT_AM ,/**< DS1307_12_AM */
	DS1307_12FORMAT_PM  /**< DS1307_12_PM */
}DS1307_12_t;

typedef enum
{
	DS1307_DAY_SUNDAY	= 1	,
	DS1307_DAY_MONDAY	    ,
	DS1307_DAY_TUESDAY	    ,
	DS1307_DAY_WEDNESDAY    ,
	DS1307_DAY_THURSDAY	    ,
	DS1307_DAY_FRIDAY		,
	DS1307_DAY_SATURDAY 	,

}DS1307_DAY_t;

/*==============================================================================================================================================
 * CONFIGURATION STRUCTURE
 *==============================================================================================================================================*/


typedef struct
{
	uint8_t       Seconds 		; /*!< SECONDS 0-59 !>*/
	uint8_t 	  Minutes 		; /*!< MINUTES 0-59 !>*/
	uint8_t 	  Hours   		; /*!< HOURS  : 12HOUR -> 1-12
												24HOUR -> 0-23 !>*/
	DS1307_12_t   _12Format		; /*!< AM / PM SPECIFICATION IN CASE OF 12 HOURS FORMAT ONLY
									 FOR INFO CHECK @DS1307_12_t !>*/
	DS1307_DAY_t  Day			; /*!< WEEK DAYS , CHECK @DS1307_DAY_t >!*/
	uint8_t		  Date			; /*!< DATE >!*/
	uint8_t 	  Month			; /*!< MONTH 1-12 >!*/
	uint8_t 	  Year			; /*!< YEAR >!*/

}DS1307_Config_t;

/*==============================================================================================================================================
 * PROTOTYPES SECTION
 *==============================================================================================================================================*/

/**
 * @fn 		: HDS1307_eInit
 * @brief 	: THIS FUNCTION INITIALIZES DS1307 MODULE THROUGH I2C COMMUNICATION
 * @param 	: Copy_I2CConfig => A POINTER TO STRUCTURE HOLDING I2C CONFIGURATION INFO
 * @return	: ERROR STATUS
 */
ERRORS_t HDS1307_eInit( I2C_Config_t * Copy_I2CConfig ) ;

/**
 * @fn 		: HDS1307_eWriteData
 * @brief 	: THIS FUNCTION WRITES DATA INTO RTC MODULE TO CONFIGURE DATE TIME CHARACTARISTICS
 * @param 	: Copy_pDS1307Config => A POINTER TO STRUCTURE HOLDING DS1307 CONFIGURATION INFO
 * @return	: ERROR STATUS
 */
ERRORS_t HDS1307_eWriteData( DS1307_Config_t * Copy_pDS1307Config ) ;

/**
 * @fn 		: HDS1307_eReadData
 * @brief 	: THIS FUNCTION READS DATA FROM DS1307 RTC MODULE IN TERMS OF DS1307 STRUCTURE
 * @param 	: Copy_pDS1307_DataToRead => A POINTER TO STRUCTURE WILL HOLD DATA READ FROM RTC MODULE
 * @return	: ERROR STATUS
 */
ERRORS_t HDS1307_eReadData( DS1307_Config_t * Copy_pDS1307_DataToRead ) ;

#endif /* DS1307_INC_DS1307_INTERFACE_H_ */
