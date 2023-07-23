/*
 ******************************************************************************
 * @file           : EXTI_Interface.h
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
#ifndef EXTI_INC_EXTI_INTERFACE_H_
#define EXTI_INC_EXTI_INTERFACE_H_

/* ======================================================================
 * EXTI Option Enums
 * ====================================================================== */

/**
 * @enum  : @TRIG_SELECT_t
 * @brief : This Enum Holds Options For Trigger Detection Source To Choose From while Initializing EXTI
 *
 */

typedef enum
{
	RISING_TRIG = 0 , FALLING_TRIG , RISING_FALLING_TRIG

}TRIG_SELECT_t;

/**
 * @enum  : @EXTI_PEND_t
 * @brief : This Enum Hold Values of Pending Status of An EXTI Line
 *
 */
typedef enum
{

	NOT_PENDED = 0 ,
	PENDED

}EXTI_PEND_t;


/**
 * @enum  : @EXTI_STATE_t
 * @brief : This Enum Holds Options For Initial Value of a Specific EXTI Line While Initializing it if
 *            masked ( DISABLED ) or not masked ( ENABLED ) .
 */

typedef enum
{
	DISABLED =0 , ENABLED

}EXTI_STATE_t;


/**
 * @enum  : @EXTI_LINE_t
 * @brief : This Enum Holds All Available Options for EXTI LINES To Choose From them while Initialization
 *
 */

typedef enum
{
	EXTI0 = 0 , EXTI1 , EXTI2 , EXTI3 , EXTI4 , EXTI5 , EXTI6 , EXTI7 , EXTI8 , EXTI9 , EXTI10 , EXTI11 , EXTI12 , EXTI13 ,
	EXTI14 , EXTI15 , EXTI16 , EXTI17 , EXTI18 , EXTI20 = 20 , EXTI21 , EXTI22

}EXTI_LINE_t;


/* ======================================================================
 * EXTI Config Structure
 * ====================================================================== */

typedef struct
{
	EXTI_LINE_t EXTILine ;
	TRIG_SELECT_t TriggerSelection ;
	EXTI_STATE_t EXTIStatus ;
	void ( *Copy_PtrFuncEXTI )( void ) ;

}EXTI_CONFG_t;



/* ------------------------------------------------------------------------------------------------ */
/* ------------------------------- FUCTION PROTOTYPES SECTION START ------------------------------- */
/* ------------------------------------------------------------------------------------------------ */

/**
 * @fn    : EXTI_Init
 * @brief : This Function Initializes a Specific EXTI Line With Some Specific Values
 * @param : EXTIConfiguration ( Pointer to Structure )   ->   1- EXTILine => Required EXTI Line To Initialize from all available EXTI Lines
 *                                                            2- TriggerSelection => Trigger Detection Source That Generates an Interrupt Request on a Specified EXTI Line
 *                                                            3- EXTIStatus => Initial State of EXTI Line ENABLED ( NOT MASKED ) OR DISABLED ( MASKED )
 *                                                            4- Copy_PtrFuncEXTI => Call Back PTR To Function To Be Generated When an Inerrupt is Issued
 * @return : ErrorStatus To Indicate if Function Worked Properly
 */
ERRORS_t EXTI_Init( const EXTI_CONFG_t  * EXTIConfiguration ) ;


/**
 * @fn    : EXTI_SetRisingTrig
 * @brief : This Function Sets the Trigger to Rising For A specific EXTI Line
 * @param : EXTILine => From Available EXTI Lines Provided in enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if function worked properly
 */

ERRORS_t EXTI_SetRisingTrig( EXTI_LINE_t EXTILine ) ;



/**
 * @fn    : EXTI_SetFallingTrig
 * @brief : This Function Sets the Trigger to Falling For A specific EXTI Line
 * @param : EXTILine => From Available EXTI Lines Provided in enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if function worked properly
 */

ERRORS_t EXTI_SetFallingTrig( EXTI_LINE_t EXTILine ) ;


/**
 * @fn    : EXTI_SetRisingFallingTrig
 * @brief : This Function Sets the Trigger to Both Rising and Falling For A specific EXTI Line
 * @param : EXTILine => From Available EXTI Lines Provided in enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if function worked properly
 */

ERRORS_t EXTI_SetRisingFallingTrig( EXTI_LINE_t EXTILine ) ;



/**
 * @fn    : EXTI_EnableInt
 * @brief : This Function Takes a Specific EXTI Line And Enables IT
 * @param : EXTILine -> Required EXTI Line to Enable It From enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_EnableInt( EXTI_LINE_t EXTILine ) ;




/**
 * @fn    : EXTI_DisableInt
 * @brief : This Function Takes a Specific EXTI Line And Disables IT
 * @param : EXTILine -> Required EXTI Line to Disable It From enum ( @EXTI_LINE_t )
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_DisableInt( EXTI_LINE_t EXTILine ) ;


/**
 * @fn    : EXTI_ClearPendingFlag
 * @brief : This Function Take A Specific EXTI Line & Clears It's Corresponding Pending Flag
 * @param : EXTILine -> Required EXTI Line to Clear It's Corresponding Pending Flag
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_ClearPendingFlag( EXTI_LINE_t EXTILine ) ;


/**
 * @fn    : EXTI_ReadPendingFlag
 * @brief : This Function Take A Specific EXTI Line & Reads It's Corresponding Pending Flag in A Pointer
 * @param : EXTILine -> Required EXTI Line to Clear It's Pending Flag
 * @param : EXTIStatus -> A Pointer to Put the Pending Status init ( NOT_PENDED OR PENDED ) from enum ( @EXTI_PEND_t )
 * @return: ErrorStatus to Indicate if Function Worked Correctly or Not
 */

ERRORS_t EXTI_ReadPendingFlag( EXTI_LINE_t EXTILine , EXTI_PEND_t * EXTIStatus ) ;



/* ---------------------------------------------------------------------------------------------- */
/* ------------------------------- FUCTION PROTOTYPES SECTION END ------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

#endif /* EXTI_INC_EXTI_INTERFACE_H_ */
