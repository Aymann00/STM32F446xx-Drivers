/*
 ******************************************************************************
 * @file           : SYSCFG_Program.c
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

#include "../Inc/SYSCFG_Interface.h"
#include "../Inc/SYSCFG_Private.h"


/*==============================================================================================================================================
 * INCLUDES SECTION END
 *==============================================================================================================================================*/



/*==============================================================================================================================================
 * MODULES IMPLEMENTATION
 *==============================================================================================================================================*/

/**
 * @fn    : SYSCFG_SetEXTIPort
 * @brief : This Function Sets A Specific Port for A Specific External Interrupt Line
 * @param : EXTI_Line -> Options of All Available EXTI Lines From enum ( @EXTI_t )
 * @param : GPIO_PORT -> Options of All Available Ports From enum ( @GPIO_PORT_t )
 * @return: ErrorStatus to Indicate if function Worked Correctly or NOT
 */
ERRORS_t SYSCFG_SetEXTIPort ( EXTI_t EXTI_Line , GPIO_PORT_t GPIO_PORT )
{
	ERRORS_t Local_u8ErrorStatus = OK ;

	/* Variable To Hold The Required Register to Access */
	uint8_t REG_Number = ( EXTI_Line / 4 ) ;

	/* Variable to Hold The Required Bits to Access */
	uint8_t BITS_Start = ( ( EXTI_Line % 4 ) * 4 ) ;

	if( ( EXTI_Line > EXTI_LINE15 ) || ( EXTI_Line < EXTI_LINE0 ) ||
			( GPIO_PORT > GPIO_PORTH ) || ( GPIO_PORT < GPIO_PORTA ) )
	{
		Local_u8ErrorStatus = NOK ;
	}
	else
	{
		/* BIT MASKING : Clearing The Required 4 Bits */
		SYSCFG->EXTICR[ REG_Number ] &= ( ~ ( EXTICRx_MASK_BITS << BITS_Start ) ) ;

		/* Set The Required Port for the Required External Interrupt Line */
		SYSCFG->EXTICR[ REG_Number ] |= ( GPIO_PORT << BITS_Start ) ;
	}
	return Local_u8ErrorStatus ;
}

