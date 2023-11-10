/*
 ******************************************************************************
 * @file           : DS1307_Config.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : Nov 10, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 ******************************************************************************
 */
#ifndef DS1307_INC_DS1307_CONFIG_H_
#define DS1307_INC_DS1307_CONFIG_H_

/**
 * @enum	: @DS1307_HOUR_t
 * @brief 	: HOLDS HOUR FORMAT TYPES
 *
 */
typedef enum
{
	DS1307_HOUR_24FORMAT ,/**< DS1307_HOUR_24FORMAT */
	DS1307_HOUR_12FORMAT  /**< DS1307_HOUR_12FORMAT */

}DS1307_HOUR_t;

#define DS1307_HOUR_FORMAT  DS1307_HOUR_24FORMAT

#endif /* DS1307_INC_DS1307_CONFIG_H_ */
