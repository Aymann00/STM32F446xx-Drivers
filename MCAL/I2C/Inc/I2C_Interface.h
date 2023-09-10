/*
 ******************************************************************************
 * @file           : I2C_Interface.h
 * @Author         : Mohammed Ayman Shalaby
 * @brief          : Main program body
 * @Date           : Aug 24, 2023
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
#ifndef I2C_INC_I2C_INTERFACE_H_
#define I2C_INC_I2C_INTERFACE_H_

typedef enum
{
	I2C_2MHz_FREQ = 2,
	I2C_3MHz_FREQ = 3,
	I2C_4MHz_FREQ = 4,
	I2C_5MHz_FREQ = 5,
	I2C_6MHz_FREQ = 6,
	I2C_7MHz_FREQ = 7,
	I2C_8MHz_FREQ = 8,
	I2C_9MHz_FREQ = 9,
	I2C_10MHz_FREQ = 10,
	I2C_11MHz_FREQ = 11,
	I2C_12MHz_FREQ = 12,
	I2C_13MHz_FREQ = 13,
	I2C_14MHz_FREQ = 14,
	I2C_15MHz_FREQ = 15,
	I2C_16MHz_FREQ = 16,
	I2C_17MHz_FREQ = 17,
	I2C_18MHz_FREQ = 18,
	I2C_19MHz_FREQ = 19,
	I2C_20MHz_FREQ = 20,
	I2C_21MHz_FREQ = 21,
	I2C_22MHz_FREQ = 22,
	I2C_23MHz_FREQ = 23,
	I2C_24MHz_FREQ = 24,
	I2C_25MHz_FREQ = 25,
	I2C_26MHz_FREQ = 26,
	I2C_27MHz_FREQ = 27,
	I2C_28MHz_FREQ = 28,
	I2C_29MHz_FREQ = 29,
	I2C_30MHz_FREQ = 30,
	I2C_31MHz_FREQ = 31,
	I2C_32MHz_FREQ = 32,
	I2C_33MHz_FREQ = 33,
	I2C_34MHz_FREQ = 34,
	I2C_35MHz_FREQ = 35,
	I2C_36MHz_FREQ = 36,
	I2C_37MHz_FREQ = 37,
	I2C_38MHz_FREQ = 38,
	I2C_39MHz_FREQ = 39,
	I2C_40MHz_FREQ = 40,
	I2C_41MHz_FREQ = 41,
	I2C_42MHz_FREQ = 42,
	I2C_43MHz_FREQ = 43,
	I2C_44MHz_FREQ = 44,
	I2C_45MHz_FREQ = 45,

} I2C_FREQ_t;

typedef enum
{
	I2C_7BIT_ADDRESS_MODE = 0,
	I2C_10BIT_ADDRESS_MODE = 1,

} I2C_ADDRESSING_MODE_t;

typedef enum
{
	I2C_SM= 0 ,
	I2C_FM_DUTY_ = 1,

} I2C_MASTER_MODE_t;

typedef struct
{
	I2C_FREQ_t Frequency;
	I2C_ADDRESSING_MODE_t AddressMode;
	uint16_t NodeAddress;
}

#endif /* I2C_INC_I2C_INTERFACE_H_ */
