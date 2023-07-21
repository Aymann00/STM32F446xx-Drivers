/*
 ******************************************************************************
 * @file           : RCC_Private.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : May 4, 2023
 * @Target         : STM32F446xx
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef RCC_RCC_PRIVATE_H_
#define RCC_RCC_PRIVATE_H_


/*=========================================
 * MASKS
 *=========================================*/
#define PLLR_MASK       0x8FFFFFFFUL
#define PLLQ_MASK       0xF0FFFFFFUL
#define PLLP_MASK       0xFFFCFFFFUL
#define PLLN_MASK       0xFFFF803FUL
#define PLLM_MASK       0xFFFFFFC0UL

#define SW_MASK         0xFFFFFFFCUL
#define SWS_MASK        0x0000000CUL

#define AHB_PRE_MASK    0xFFFFFF0FUL
#define APB1_PRE_MASK   0xFFFFE3FFUL
#define APB2_PRE_MASK   0xFFFF1FFFUL


/*=========================================
 * MACROS
 *=========================================*/
#define TIMOUT_MAX      400



#endif /* RCC_RCC_PRIVATE_H_ */
