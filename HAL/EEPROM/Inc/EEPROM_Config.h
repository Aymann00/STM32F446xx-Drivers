/*
 ******************************************************************************
 * @file           : EEPROM_Config.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : Nov 12, 2023
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 Ayman.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#ifndef INC_EEPROM_CONFIG_H_
#define INC_EEPROM_CONFIG_H_

typedef enum
{
	EEPROM_MEM_DEVICE_0 = 0 ,
	EEPROM_MEM_DEVICE_1
}EEPROM_MEM_DEVICE_t;

#define EEPROM_MEM_DEVICE  EEPROM_MEM_DEVICE_0

#endif /* INC_EEPROM_CONFIG_H_ */
