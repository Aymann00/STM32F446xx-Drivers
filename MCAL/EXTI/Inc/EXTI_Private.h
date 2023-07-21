/*
 ******************************************************************************
 * @file           : EXTI_Private.h
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
#ifndef EXTI_INC_EXTI_PRIVATE_H_
#define EXTI_INC_EXTI_PRIVATE_H_


/* ======================================================================
 * MACROS
 * ====================================================================== */
#define PENDING_FLAG_IS_SET   1

/* ======================================================================
 * PRIVATE FUNCTION
 * ====================================================================== */

/**
 * @fn    : EXTI_CheckConfig
 * @brief : This Function Check on Configuration Structure Passed By the User
 * @param : EXTIConfig -> Pointer to the Configuration Structure
 * @return: ErrorStatus to Indicate if Configuration or Correct or NOT
 * @note  : Private Function
 */

static ERRORS_t EXTI_CheckConfig ( EXTI_CONFG_t * EXTIConfig ) ;

#endif /* EXTI_INC_EXTI_PRIVATE_H_ */
