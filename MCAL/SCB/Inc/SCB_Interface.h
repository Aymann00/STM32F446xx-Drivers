/*
 ******************************************************************************
 * @file           : SCB_Interface.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : Jul 12, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 ******************************************************************************
 */
#ifndef SCB_INC_SCB_INTERFACE_H_
#define SCB_INC_SCB_INTERFACE_H_

/* ======================================================================
 * SCB Option Enums
 * ====================================================================== */

/**
 * @enum  : @PRIGROUP_t
 * @brief : Options For the User To Choose Number of Groups and Subs By dividing the 4 Bits
 *            of the Priority Registers Between Groups and Subs
 *
 */
typedef enum
{
	SIXTEEN_GROUP_NO_SUB = 0 , EIGHT_GROUP_TWO_SUB = 4 , FOUR_GROUP_FOUR_SUB , TWO_GROUP_EIGHT_SUB , NO_GROUP_SIXTEEN_SUB
}PRIGROUP_t;

/**
 * @enum  : @FAULT_t
 * @brief : This Enum Holds Options For Faults To Enable or Disable Specified Fault
 * 
 */
typedef enum
{
	UNALIGNED_TRAP = 3 ,  /* Generates USAGE_FAULT If Enabled */
	DIVISION_0_TRAP ,     /* Generates USAGE_FAULT If Enabled */
	MEM_MANAGE_FAULT = 16,/* MEM_MANAGE_FAULT */
	BUS_FAULT ,           /* BUS_FAULT */
	USAGE_FAULT ,         /* USAGE_FAULT */
}FAULT_t;

typedef enum
{
	NMI_HANDLER = 0 , HARDFAULT_HANDLER , MEMMANAGE_HANDLER , BUSFAULT_HANDLER , USAGEFAULT_HANDLER , SVCALL_HANDLER , DEBUGMONITOR_HANDLER , PENDSV_HANDLER

}HANDLER_t;

/* ------------------------------------------------------------------------------------------------ */
/* ------------------------------- FUCTION PROTOTYPES SECTION START ------------------------------- */
/* ------------------------------------------------------------------------------------------------ */

/**
 * @fn    : SCB_SetPriorityGroup
 * @brief : This Function Set the Priority Group Which Make the division between  Group Priority Bits and Sub Priority Bits
 * @param : PriorityGroup -> From enum ( @PRIGROUP_t )
 * @retval: ErrorStatus to Indicate if Function Worked Correct or Not ( OK , NOK )
 */
ERRORS_t SCB_SetPriorityGroup( PRIGROUP_t PriorityGroup ) ;

/**
 * @fn     : SCB_ENAFault
 * @brief  : This Function Enables a Specifed Fault Exception Like MemManage , Usage , Bus Fault OR Faults That Cause Usage Fault Like Division By 0 & Unaligned Data Access
 * @param  : FaultEXC -> From enum ( FAULT_t )
 * @return : ErrorStatus To Indicate if Function Worked Correctly or Not
 */
ERRORS_t SCB_ENAFault ( FAULT_t FaultEXC ) ;


/**
 * @fn     : SCB_DISAFault
 * @brief  : This Function Disables a Specifed Fault Exception Like MemManage , Usage , Bus Fault OR Faults That Cause Usage Fault Like Division By 0 & Unaligned Data Access
 * @param  : FaultEXC -> From enum ( FAULT_t )
 * @return : ErrorStatus To Indicate if Function Worked Correctly or Not
 */
ERRORS_t SCB_DISAFault ( FAULT_t FaultEXC ) ;


/**
 * @fn     : SCB_SetEXCCallBack
 * @brief  : This Function Sets Call Back Function of the Specified Handler
 * @param  : EXC_Handler -> From enum ( HANDLER_t )
 * @param  : Copy_PtrToFunction -> Pointer to Functoin that Points to the Specified ISR
 * @return : ErrorStatus To Indicate if Function Worked Correctly or Not
 */
ERRORS_t SCB_SetEXCCallBack( void( *Copy_PtrToFunction )(void) , HANDLER_t EXC_Handler ) ;

/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- FUCTION PROTOTYPES SECTION END ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */


#endif /* SCB_INC_SCB_INTERFACE_H_ */
