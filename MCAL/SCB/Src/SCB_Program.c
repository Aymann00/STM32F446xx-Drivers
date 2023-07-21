/*
 ******************************************************************************
 * @file           : SCB_Program.c
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : Jul 12, 2023
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

#include "../Inc/SCB_Interface.h"
#include "../Inc/SCB_Private.h"

/*==============================================================================================================================================
 * INCLUDES SECTION END
 *==============================================================================================================================================*/


/*==============================================================================================================================================
 * GLOBAL VARIABLES SECTION
 *==============================================================================================================================================*/

void (*SCB_PTR_TO_FUNCTION[8])(void) = { NULL } ;


/*==============================================================================================================================================
 * MODULES IMPLEMENTATION
 *==============================================================================================================================================*/

/**
 * @fn    : SCB_SetPriorityGroup
 * @brief : This Function Set the Priority Group Which Make the division between  Group Priority Bits and Sub Priority Bits
 * @param : PriorityGroup -> From enum ( @PRIGROUP_t )
 * @retval: ErrorStatus to Indicate if Function Worked Correct or Not ( OK , NOK )
 */
ERRORS_t SCB_SetPriorityGroup( PRIGROUP_t PriorityGroup )
{
	ERRORS_t Local_u8ErrorSatus = OK ;

	/* Check on PRIGROUP Provided */
	if( (PriorityGroup >= SIXTEEN_GROUP_NO_SUB) && (PriorityGroup <= NO_GROUP_SIXTEEN_SUB) )
	{
		/* BIT MASKING */

		/* Clearing All Bits Except VECTKEY */
		SCB->AIRCR &= ( 0x05FA << 16 ) ;

		/* Setting PRIGROUP */
		SCB->AIRCR  = ( 0x05FA << 16 ) | ( PriorityGroup << 8 ) ;
	}
	else
	{
		Local_u8ErrorSatus = NOK ;
	}
	return Local_u8ErrorSatus ;
}

/**
 * @fn     : SCB_ENAFault
 * @brief  : This Function Enables a Specifed Fault Exception Like MemManage , Usage , Bus Fault OR Faults That Cause Usage Fault Like Division By 0 & Unaligned Data Access
 * @param  : FaultEXC -> From enum ( FAULT_t )
 * @return : ErrorStatus To Indicate if Function Worked Correctly or Not
 */
ERRORS_t SCB_ENAFault ( FAULT_t FaultEXC )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	/* Check on Provided Fault Exception */
	if( ( FaultEXC < UNALIGNED_TRAP ) || ( FaultEXC > USAGE_FAULT ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		SCB->SHCSR |= ( 1 << FaultEXC ) ;
	}
	return Local_u8ErrorStatus ;
}



/**
 * @fn     : SCB_DISAFault
 * @brief  : This Function Disables a Specifed Fault Exception Like MemManage , Usage , Bus Fault OR Faults That Cause Usage Fault Like Division By 0 & Unaligned Data Access
 * @param  : FaultEXC -> From enum ( FAULT_t )
 * @return : ErrorStatus To Indicate if Function Worked Correctly or Not
 */
ERRORS_t SCB_DISAFault ( FAULT_t FaultEXC )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	/* Check on Provided Fault Exception */
	if( ( FaultEXC < UNALIGNED_TRAP ) || ( FaultEXC > USAGE_FAULT ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		SCB->SHCSR &= ( ~ ( 1 << FaultEXC ) ) ;
	}
	return Local_u8ErrorStatus ;
}


/**
 * @fn     : SCB_SetEXCCallBack
 * @brief  : This Function Sets Call Back Function of the Specified Handler
 * @param  : EXC_Handler -> From enum ( @HANDLER_t )
 * @param  : Copy_PtrToFunction -> Pointer to Functoin that Points to the Specified ISR
 * @return : ErrorStatus To Indicate if Function Worked Correctly or Not
 */
ERRORS_t SCB_SetEXCCallBack( void( *Copy_PtrToFunction )(void) , HANDLER_t EXC_Handler )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	if( Copy_PtrToFunction != NULL )
	{
		/* Assign Global Pointer to Func of Handler to the Local Pointer to Function */
		SCB_PTR_TO_FUNCTION[ EXC_Handler ] = Copy_PtrToFunction ;
	}
	else
	{
		Local_u8ErrorStatus = NULL_POINTER ;
	}
	return Local_u8ErrorStatus ;
}


/*==============================================================================================================================================
 * HANDLERS SECTION
 *==============================================================================================================================================*/

/* EXC0 */
void NMI_Handler( void )
{
	if( SCB_PTR_TO_FUNCTION[ NMI_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ NMI_HANDLER ] () ;
	}
}
/* EXC1 */
void HardFault_Handler ( void )
{
	if( SCB_PTR_TO_FUNCTION[ HARDFAULT_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ HARDFAULT_HANDLER ]() ;
	}
}
/* EXC2 */
void MemManage_Handler ( void )
{
	if( SCB_PTR_TO_FUNCTION[ MEMMANAGE_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ MEMMANAGE_HANDLER ]() ;
	}
}
/* EXC3 */
void BusFault_Handler ( void )
{
	if( SCB_PTR_TO_FUNCTION[ BUSFAULT_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ BUSFAULT_HANDLER ]() ;
	}
}
/* EXC4 */
void UsageFault_Handler ( void )
{
	if( SCB_PTR_TO_FUNCTION[ USAGEFAULT_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ USAGEFAULT_HANDLER ]() ;
	}
}
/* EXC5 */
void SVC_Handler ( void )
{
	if( SCB_PTR_TO_FUNCTION[ SVCALL_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ SVCALL_HANDLER ] () ;
	}
}
/* EXC6 */
void DebugMon_Handler ( void )
{
	if( SCB_PTR_TO_FUNCTION[ DEBUGMONITOR_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ DEBUGMONITOR_HANDLER ] () ;
	}
}
/* EXC7 */
void PendSV_Handler ( void )
{
	if( SCB_PTR_TO_FUNCTION[ PENDSV_HANDLER ] != NULL )
	{
		SCB_PTR_TO_FUNCTION[ PENDSV_HANDLER ] ()  ;
	}
}


