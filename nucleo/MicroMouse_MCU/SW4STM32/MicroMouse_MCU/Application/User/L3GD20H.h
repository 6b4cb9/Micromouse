/*
 * L3GD20H.h
 *
 *  Created on: 15 sie 2017
 *      Author: Marcin Rosenhof
 */

#ifndef APPLICATION_USER_L3GD20H_H_
#define APPLICATION_USER_L3GD20H_H_

#include "stm32f4xx_hal.h"
#include "i2c.h"

#define GYRO_ADDRESS   			0b1101011
#define GYRO_SHIFTED_ADDRESS 	(GYRO_ADDRESS << 1)
#define GYRO_DEVICE				&hi2c1

extern I2C_HandleTypeDef hi2c1;

typedef enum gyro_regAddr
{
	gyro_WHO_AM_I       = 0x0F,

	gyro_CTRL1          = 0x20,
	gyro_CTRL2          = 0x21,
	gyro_CTRL3          = 0x22,
	gyro_CTRL4          = 0x23,
	gyro_CTRL5          = 0x24,
	gyro_REFERENCE      = 0x25,
	gyro_OUT_TEMP       = 0x26,
	gyro_STATUS         = 0x27,

	gyro_OUT_X_L        = 0x28,
	gyro_OUT_X_H        = 0x29,
	gyro_OUT_Y_L        = 0x2A,
	gyro_OUT_Y_H        = 0x2B,
	gyro_OUT_Z_L        = 0x2C,
	gyro_OUT_Z_H        = 0x2D,

	gyro_FIFO_CTRL      = 0x2E,
	gyro_FIFO_SRC       = 0x2F,

	gyro_IG_CFG         = 0x30,
	gyro_IG_SRC         = 0x31,
	gyro_IG_THS_XH      = 0x32,
	gyro_IG_THS_XL      = 0x33,
	gyro_IG_THS_YH      = 0x34,
	gyro_IG_THS_YL      = 0x35,
	gyro_IG_THS_ZH      = 0x36,
	gyro_IG_THS_ZL      = 0x37,
	gyro_IG_DURATION    = 0x38,

	gyro_LOW_ODR        = 0x39
}gyro_regAddr;

inline HAL_StatusTypeDef gyro_writeReg(gyro_regAddr adr, uint8_t value){
	return HAL_I2C_Mem_Write(&hi2c1, GYRO_SHIFTED_ADDRESS, (uint8_t)adr, 1, &value, 1, 10);
}

inline HAL_StatusTypeDef gyro_readReg(gyro_regAddr adr, uint8_t * value){
	return HAL_I2C_Mem_Read(&hi2c1, GYRO_SHIFTED_ADDRESS, (uint8_t)adr, 1, value, 1, 10);
}

#endif /* APPLICATION_USER_L3GD20H_H_ */
