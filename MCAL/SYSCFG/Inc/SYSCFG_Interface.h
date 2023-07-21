/*
 ******************************************************************************
 * @file           : SYSCFG_Interface.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Interface File
 * @Date           : Jul 20, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef SYSCFG_INC_SYSCFG_INTERFACE_H_
#define SYSCFG_INC_SYSCFG_INTERFACE_H_

/* ======================================================================
 * SYSCFG Option Enums
 * ====================================================================== */

/**
 * @enum  : @EXTI_t
 * @brief : This Enum Holds Options of All EXTI Lines Available that is Supposed to Be Used in SYSCFG Functions
 *
 */
typedef enum
{
	EXTI_LINE0 = 0 , EXTI_LINE1 , EXTI_LINE2 , EXTI_LINE3 , EXTI_LINE4 , EXTI_LINE5 , EXTI_LINE6 , EXTI_LINE7 ,EXTI_LINE8 ,
	EXTI_LINE9 , EXTI_LINE10 , EXTI_LINE11 , EXTI_LINE12 , EXTI_LINE13 , EXTI_LINE14 , EXTI_LINE15

}EXTI_t;

/**
 * @enum  : GPIO_PORT_t
 * @brief : This Enum HOlds Options for All Available Ports To Choose For A Specific EXTI Line
 *
 */
typedef enum
{
	GPIO_PORTA = 0 , GPIO_PORTB , GPIO_PORTC , GPIO_PORTD , GPIO_PORTE , GPIO_PORTF , GPIO_PORTG , GPIO_PORTH

}GPIO_PORT_t;

/* ------------------------------------------------------------------------------------------------ */
/* ------------------------------- FUCTION PROTOTYPES SECTION START ------------------------------- */
/* ------------------------------------------------------------------------------------------------ */

/**
 * @fn    : SYSCFG_SetEXTIPort
 * @brief : This Function Sets A Specific Port for A Specific External Interrupt Line
 * @param : EXTI_Line -> Options of All Available EXTI Lines From enum ( @EXTI_t )
 * @param : GPIO_PORT -> Options of All Available Ports From enum ( @GPIO_PORT_t )
 * @return: ErrorStatus to Indicate if function Worked Correctly or NOT
 */
ERRORS_t SYSCFG_SetEXTIPort ( EXTI_t EXTI_Line , GPIO_PORT_t GPIO_PORT ) ;

#endif /* SYSCFG_INC_SYSCFG_INTERFACE_H_ */
