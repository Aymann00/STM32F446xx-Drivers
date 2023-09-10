/*
 ******************************************************************************
 * @file           : ErrType.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : ERROR TYPES FILE
 * @Date           : May 6, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef ERRTYPE_H_
#define ERRTYPE_H_

/*==============================================================================================================================================
 * MANDATORY MACROS
 *==============================================================================================================================================*/
#define NULL ((void *)0)

typedef enum
{
	/*=======================
	 * GENERAL PURPOSE ERRORS
	 *=======================*/
	OK,
	NOK,
	NULL_POINTER,
	/*===========
	 * RCC ERRORS
	 *===========*/
	CLK_STATE_ERROR,
	CLK_TYPE_ERROR,
	PLL_SRC_ERROR,
	TIME_OUT_ERROR,
	SYS_CLK_ERROR,
	AHB_PRE_ERROR,
	APB1_PRE_ERROR,
	APB2_PRE_ERROR,
	HSE_CONFIG_ERROR,
	PERIPHERAL_ENABLE_ERROR,
	PERIPHERAL_DISABLE_ERROR,
	BUS_ERROR,
	/*============
	 * GPIO ERRORS
	 *============*/
	GPIO_NOK,
	GPIO_VALID,
	GPIO_NOT_VALID,
	/*============
	 * EXTI ERRORS
	 *============*/
	EXTI_NOK,
	EXTI_OK,
	/*============
	 * DMA ERRORS
	 *============*/
	DMA_OK,
	DMA_NOK,
	DMA_WRONG_CONFIGURATION,
	/*==============
	 * USART ERRORS
	 *==============*/
	USART_OK,
	USART_NOK,
	USART_WRONG_CONFIGURATION,
	/*==============
	 * SPI ERRORS
	 *==============*/
	SPI_OK,
	SPI_NOK,
	SPI_INVALID_CONFIG,

} ERRORS_t;

#endif /* ERRTYPE_H_ */
