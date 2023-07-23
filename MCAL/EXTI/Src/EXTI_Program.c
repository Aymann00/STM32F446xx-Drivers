/*
 ******************************************************************************
 * @file           : EXTI_Program.c
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : Jul 20, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */

/*==============================================================================================================================================
 * INCLUDES SECTION START
 *==============================================================================================================================================*/
#include <stdint.h>

#include "../../../LIB/ErrType.h"
#include "../../../LIB/STM32F446xx.h"

#include "../Inc/EXTI_Interface.h"
#include "../Inc/EXTI_Private.h"

/*==============================================================================================================================================
 * INCLUDES SECTION END
 *==============================================================================================================================================*/


/*==============================================================================================================================================
 * GLOBAL VARIABLES SECTION START
 *==============================================================================================================================================*/

void (*EXTI_PTR_TO_FUNCTION[23])(void) = { NULL } ;

/*==============================================================================================================================================
 * GLOBAL VARIABLES SECTION END
 *==============================================================================================================================================*/



/*==============================================================================================================================================
 * MODULES IMPLEMENTATION
 *==============================================================================================================================================*/

/**
 * @fn    : EXTI_Init
 * @brief : This Function Initializes a Specific EXTI Line With Some Specific Values ( EXTI Line , Trigger Detection Source , EXTI Initial State , Ptr to Function ( Call Back Func ) )
 * @param : EXTIConfiguration ( Pointer to Structure )   ->   1- EXTILine => Required EXTI Line To Initialize from all available EXTI Lines
 *                                                            2- TriggerSelection => Trigger Detection Source That Generates an Interrupt Request on a Specified EXTI Line
 *                                                            3- EXTIStatus => Initial State of EXTI Line ENABLED ( NOT MASKED ) OR DISABLED ( MASKED )
 *                                                            4- Copy_PtrFuncEXTI => Call Back PTR To Function To Be Generated When an Inerrupt is Issued
 * @return : ErrorStatus To Indicate if Function Worked Properly
 */
ERRORS_t EXTI_Init( const EXTI_CONFG_t * EXTIConfiguration )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( EXTI_OK == EXTI_CheckConfig( EXTIConfiguration )  )
	{
		/* Correct Configuration */

		/* Initialize Call Back Function */
		EXTI_PTR_TO_FUNCTION[ EXTIConfiguration->EXTILine ] = EXTIConfiguration->Copy_PtrFuncEXTI ;

		/* Set Trigger Edge Detection */
		if( RISING_TRIG == EXTIConfiguration->TriggerSelection )
		{
			EXTI_SetRisingTrig( EXTIConfiguration->EXTILine ) ;
		}
		else if( FALLING_TRIG == EXTIConfiguration->TriggerSelection )
		{
			EXTI_SetFallingTrig( EXTIConfiguration->EXTILine ) ;
		}
		else
		{
			/* Both Rising & Falling */
			EXTI_SetRisingFallingTrig( EXTIConfiguration->EXTILine ) ;
		}

		/* Initial Enable / Disable Config */
		EXTI->IMR &= ( ~ ( 1 << EXTIConfiguration->EXTILine ) ) ;
		EXTI->IMR |= ( ( EXTIConfiguration->EXTIStatus ) << ( EXTIConfiguration->EXTILine ) ) ;
	}
	else
	{
		/*  Wrong Configuration Options or Null Function to Pointer*/
		Local_u8ErrorStatus = NOK ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn    : EXTI_SetRisingTrig
 * @brief : This Function Sets the Trigger to Rising For A specific EXTI Line
 * @param : EXTILine => From Available EXTI Lines Provided in enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if function worked properly
 */

ERRORS_t EXTI_SetRisingTrig( EXTI_LINE_t EXTILine )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( EXTILine < EXTI0 || EXTILine > EXTI22 )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		/* Set Rising Trigger */
		EXTI->RTSR |= ( 1 << EXTILine ) ;
		EXTI->FTSR &= ( ~ ( 1 << EXTILine ) ) ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn    : EXTI_SetFallingTrig
 * @brief : This Function Sets the Trigger to Falling For A specific EXTI Line
 * @param : EXTILine => From Available EXTI Lines Provided in enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if function worked properly
 */

ERRORS_t EXTI_SetFallingTrig( EXTI_LINE_t EXTILine )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( EXTILine < EXTI0 || EXTILine > EXTI22 )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		/* Set Falling Trigger */
		EXTI->FTSR |= ( 1 << EXTILine ) ;
		EXTI->RTSR &= ( ~ ( 1 << EXTILine ) ) ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn    : EXTI_SetRisingFallingTrig
 * @brief : This Function Sets the Trigger to Both Rising and Falling For A specific EXTI Line
 * @param : EXTILine => From Available EXTI Lines Provided in enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if function worked properly
 */

ERRORS_t EXTI_SetRisingFallingTrig( EXTI_LINE_t EXTILine )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( EXTILine < EXTI0 || EXTILine > EXTI22 )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		/* Set Rising Falling Trigger */
		EXTI->RTSR |= ( 1 << EXTILine ) ;
		EXTI->FTSR |= ( 1 << EXTILine ) ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn    : EXTI_EnableInt
 * @brief : This Function Takes a Specific EXTI Line And Enables IT
 * @param : EXTILine -> Required EXTI Line to Enable It From enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_EnableInt( EXTI_LINE_t EXTILine )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( ( EXTILine < EXTI0 ) || ( EXTILine > EXTI22 ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		EXTI->IMR |= ( 1 << EXTILine ) ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn    : EXTI_DisableInt
 * @brief : This Function Takes a Specific EXTI Line And Disables IT
 * @param : EXTILine -> Required EXTI Line to Disable It From enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_DisableInt( EXTI_LINE_t EXTILine )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( ( EXTILine < EXTI0 ) || ( EXTILine > EXTI22 ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		EXTI->IMR &= ( ~ ( 1 << EXTILine ) ) ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn    : EXTI_ClearPendingFlag
 * @brief : This Function Take A Specific EXTI Line & Clears It's Corresponding Pending Flag
 * @param : EXTILine -> Required EXTI Line to Clear It's Corresponding Pending Flag
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_ClearPendingFlag( EXTI_LINE_t EXTILine )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( ( EXTILine < EXTI0 ) || ( EXTILine > EXTI22 ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		/* Clear Pending Flag */
		EXTI->PR = ( 1 << EXTILine ) ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn    : EXTI_ReadPendingFlag
 * @brief : This Function Take A Specific EXTI Line & Reads It's Corresponding Pending Flag in A Pointer
 * @param : EXTILine -> Required EXTI Line to Clear It's Pending Flag
 * @param : EXTIStatus -> A Pointer to Put the Pending Status init ( NOT_PENDED OR PENDED ) from enum ( @EXTI_PEND_t )
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_ReadPendingFlag( EXTI_LINE_t EXTILine , EXTI_PEND_t * EXTIStatus )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( ( EXTILine < EXTI0 ) || ( EXTILine > EXTI22 ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		/* Read Pending Flag */
		*EXTIStatus = ( ( ( EXTI->PR ) >> EXTILine ) & 0x01 ) ;
	}
	return Local_u8ErrorStatus ;

}


/**
 * @fn    : EXTI_SetSWInt
 * @brief : This Function Allow you To Generate EXTI Line Request By Software
 * @param : EXTILine => Required EXTI Line to Generate an Interrupt Request
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_SetSWInt ( EXTI_LINE_t EXTILine )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( ( EXTILine < EXTI0 ) || ( EXTILine > EXTI22 ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		/* Set SW Interrupt */
		EXTI->SWIER = ( 1 << EXTILine ) ;
	}
	return Local_u8ErrorStatus ;
}

/**
 * @fn    : EXTI_CheckConfig
 * @brief : This Function Check on Configuration Structure Passed By the User
 * @param : EXTIConfig -> Pointer to the Configuration Structure
 * @return: ErrorStatus to Indicate if Configuration or Correct or NOT
 * @note  : Private Function
 */

static ERRORS_t EXTI_CheckConfig ( const EXTI_CONFG_t * EXTIConfig )
{
	ERRORS_t Local_u8ErrorState = EXTI_OK;

	if( ( EXTIConfig->EXTILine < EXTI0 ) || ( EXTIConfig->EXTILine > EXTI22 ) ||
			( EXTIConfig->EXTIStatus < DISABLED ) || ( EXTIConfig->EXTIStatus > ENABLED ) ||
			( EXTIConfig->TriggerSelection < RISING_TRIG ) || ( EXTIConfig->TriggerSelection > RISING_FALLING_TRIG ) )
	{
		Local_u8ErrorState = EXTI_NOK ;
	}
	else if( EXTIConfig->Copy_PtrFuncEXTI == NULL )
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}


/*==============================================================================================================================================
 * HANDLERS SECTION
 *==============================================================================================================================================*/



void EXTI1_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI1 ) ;

	if( EXTI_PTR_TO_FUNCTION[ EXTI1 ] != NULL )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI1 ] ( ) ;
	}
}

void EXTI2_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI2 ) ;

	if( EXTI_PTR_TO_FUNCTION[ EXTI2 ] != NULL )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI2 ] ( ) ;
	}
}

void EXTI3_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI3 ) ;

	if( EXTI_PTR_TO_FUNCTION[ EXTI3 ] != NULL )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI3 ] ( ) ;
	}
}

void EXTI4_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI4 ) ;

	if( EXTI_PTR_TO_FUNCTION[ EXTI4 ] != NULL )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI4 ] ( ) ;
	}
}

void EXTI9_5_IRQHandler(void)
{
	/* Variable To Hold Pending Status */
	EXTI_PEND_t PEND_Status = NOT_PENDED ;

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI5 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI5 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI5 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI5 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI6 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI6 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI6 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI6 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI7 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI7 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI7 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI7 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI8 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI8 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI8 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI8 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI9 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI9 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI9 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI9 ] ( ) ;
		}
	}

}

void EXTI15_10_IRQHandler(void)
{
	EXTI_PEND_t PEND_Status = NOT_PENDED ;

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI10 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI10 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI10 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI10 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI11 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI11 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI11 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI11 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI12 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI12 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI12 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI12 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI13 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI13 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI13 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI13 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI14 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI14 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI14 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI14 ] ( ) ;
		}
	}

	/* Read Pending */
	EXTI_ReadPendingFlag( EXTI15 , &PEND_Status ) ;

	if( PEND_Status == PENDED )
	{
		/* Clear Pending Flag */
		EXTI_ClearPendingFlag( EXTI15 ) ;

		/* Set PTR To Function */
		if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI15 ]  )
		{
			EXTI_PTR_TO_FUNCTION[ EXTI15 ] ( ) ;
		}
	}
}
/* EXTI16 */
void PVD_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI16 ) ;

	/* Set PTR To Function */
	if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI16 ]  )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI16 ] ( ) ;
	}
}
/* EXTI17 */
void RTC_Alarm_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI17 ) ;

	/* Set PTR To Function */
	if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI17 ]  )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI17 ] ( ) ;
	}
}
/* EXTI18 */
void OTG_FS_WKUP_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI18 ) ;

	/* Set PTR To Function */
	if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI18 ]  )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI18 ] ( ) ;
	}
}
/* EXTI20 */
void OTG_HS_WKUP_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI20 ) ;

	/* Set PTR To Function */
	if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI20 ]  )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI20 ] ( ) ;
	}
}
/* EXTI21 */
void TAMP_STAMP_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI21 ) ;

	/* Set PTR To Function */
	if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI21 ]  )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI21 ] ( ) ;
	}
}
/* EXTI22 */
void RTC_WKUP_IRQHandler(void)
{
	/* Clear Pending Flag */
	EXTI_ClearPendingFlag( EXTI22 ) ;

	/* Set PTR To Function */
	if( NULL != EXTI_PTR_TO_FUNCTION[ EXTI22 ]  )
	{
		EXTI_PTR_TO_FUNCTION[ EXTI22 ] ( ) ;
	}
}
