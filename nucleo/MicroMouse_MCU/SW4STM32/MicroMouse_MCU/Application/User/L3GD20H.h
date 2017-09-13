/*
 * L3GD20H.h
 *
 *  Created on: 15 sie 2017
 *      Author: Chupacabra
 */

#ifndef APPLICATION_USER_L3GD20H_H_
#define APPLICATION_USER_L3GD20H_H_

#include "stm32f4xx_hal.h"
#include "i2c.h"

#define L3GD20H_ADDRESS   			0b1101011
#define L3GD20H_SHIFTED_ADDRESS 	(L3GD20H_ADDRESS << 1)
#define MAX_DPS						245.0

extern I2C_HandleTypeDef * device;

typedef enum L3GD20H_regAddr
{
	L3GD20H_WHO_AM_I       = 0x0F,

	L3GD20H_CTRL1          = 0x20,
	L3GD20H_CTRL2          = 0x21,
	L3GD20H_CTRL3          = 0x22,
	L3GD20H_CTRL4          = 0x23,
	L3GD20H_CTRL5          = 0x24,
	L3GD20H_REFERENCE      = 0x25,
	L3GD20H_OUT_TEMP       = 0x26,
	L3GD20H_STATUS         = 0x27,

	L3GD20H_OUT_X_L        = 0x28,
	L3GD20H_OUT_X_H        = 0x29,
	L3GD20H_OUT_Y_L        = 0x2A,
	L3GD20H_OUT_Y_H        = 0x2B,
	L3GD20H_OUT_Z_L        = 0x2C,
	L3GD20H_OUT_Z_H        = 0x2D,

	L3GD20H_FIFO_CTRL      = 0x2E,
	L3GD20H_FIFO_SRC       = 0x2F,

	L3GD20H_IG_CFG         = 0x30,
	L3GD20H_IG_SRC         = 0x31,
	L3GD20H_IG_THS_XH      = 0x32,
	L3GD20H_IG_THS_XL      = 0x33,
	L3GD20H_IG_THS_YH      = 0x34,
	L3GD20H_IG_THS_YL      = 0x35,
	L3GD20H_IG_THS_ZH      = 0x36,
	L3GD20H_IG_THS_ZL      = 0x37,
	L3GD20H_IG_DURATION    = 0x38,

	L3GD20H_LOW_ODR        = 0x39
}L3GD20H_regAddr;

inline uint8_t L3GD20H_writeReg(L3GD20H_regAddr adr, uint8_t value){
	uint8_t address = (uint8_t)adr;
	HAL_I2C_Mem_Write(device, L3GD20H_SHIFTED_ADDRESS, address, 1, &value, 1, 10);
	return 0;
}

inline uint8_t L3GD20H_readReg(L3GD20H_regAddr adr){
	uint8_t value = 0;
	uint8_t address = adr;
	HAL_I2C_Mem_Read(device, L3GD20H_SHIFTED_ADDRESS, address, 1, &value, 1, 10);
	return value;
}

#endif /* APPLICATION_USER_L3GD20H_H_ */
