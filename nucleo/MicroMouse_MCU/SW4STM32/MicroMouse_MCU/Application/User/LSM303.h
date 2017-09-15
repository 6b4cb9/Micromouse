/*
 * LSM303.h
 *
 *  Created on: 22 sie 2017
 *      Author: Marcin Rosenhof
 */

#ifndef APPLICATION_USER_LSM303_H_
#define APPLICATION_USER_LSM303_H_

#include <stdbool.h>
#include "stm32f4xx_hal.h"
#include "i2c.h"

extern I2C_HandleTypeDef hi2c1;

#define ACC_ADDRESS 			0b0011101
#define ACC_SHIFTED_ADDRESS		(ACC_ADDRESS << 1)
#define ACC_DEVICE 				&hi2c1

typedef enum acc_regAddr
{
	  acc_TEMP_OUT_L        = 0x05,
	  acc_TEMP_OUT_H        = 0x06,

	  acc_STATUS_M          = 0x07,

	  acc_OUT_X_L_M         = 0x08,
	  acc_OUT_X_H_M         = 0x09,
	  acc_OUT_Y_L_M         = 0x0A,
	  acc_OUT_Y_H_M         = 0x0B,
	  acc_OUT_Z_L_M         = 0x0C,
	  acc_OUT_Z_H_M         = 0x0D,

	  acc_WHO_AM_I			= 0x0F,

	  acc_INT_CTRL_M        = 0x12,
	  acc_INT_SRC_M         = 0x13,
	  acc_INT_THS_L_M       = 0x14,
	  acc_INT_THS_H_M       = 0x15,

	  acc_OFFSET_X_L_M      = 0x16,
	  acc_OFFSET_X_H_M      = 0x17,
	  acc_OFFSET_Y_L_M      = 0x18,
	  acc_OFFSET_Y_H_M      = 0x19,
	  acc_OFFSET_Z_L_M      = 0x1A,
	  acc_OFFSET_Z_H_M      = 0x1B,
	  acc_REFERENCE_X       = 0x1C,
	  acc_REFERENCE_Y       = 0x1D,
	  acc_REFERENCE_Z       = 0x1E,

	  acc_CTRL0             = 0x1F,
	  acc_CTRL1             = 0x20,
	  acc_CTRL2             = 0x21,
	  acc_CTRL3             = 0x22,
	  acc_CTRL4             = 0x23,
	  acc_CTRL5             = 0x24,
	  acc_CTRL6             = 0x25,
	  acc_CTRL7             = 0x26,
	  acc_STATUS_A          = 0x27,

	  acc_OUT_X_L_A         = 0x28,
	  acc_OUT_X_H_A         = 0x29,
	  acc_OUT_Y_L_A         = 0x2A,
	  acc_OUT_Y_H_A         = 0x2B,
	  acc_OUT_Z_L_A         = 0x2C,
	  acc_OUT_Z_H_A         = 0x2D,

	  acc_FIFO_CTRL         = 0x2E,
	  acc_FIFO_SRC          = 0x2F,

	  acc_IG_CFG1           = 0x30,
	  acc_IG_SRC1           = 0x31,
	  acc_IG_THS1           = 0x32,
	  acc_IG_DUR1           = 0x33,
	  acc_IG_CFG2           = 0x34,
	  acc_IG_SRC2           = 0x35,
	  acc_IG_THS2           = 0x36,
	  acc_IG_DUR2           = 0x37,

	  acc_CLICK_CFG         = 0x38,
	  acc_CLICK_SRC         = 0x39,
	  acc_CLICK_THS         = 0x3A,
	  acc_TIME_LIMIT        = 0x3B,
	  acc_TIME_LATENCY      = 0x3C,
	  acc_TIME_WINDOW       = 0x3D,

	  acc_Act_THS           = 0x3E,
	  acc_Act_DUR           = 0x3F,
}acc_regAddr;

inline HAL_StatusTypeDef acc_writeReg(acc_regAddr adr, uint8_t value){
	return HAL_I2C_Mem_Write(&hi2c1, ACC_SHIFTED_ADDRESS, (uint8_t)adr, 1, &value, 1, 10);
}

inline HAL_StatusTypeDef acc_readReg(acc_regAddr adr, uint8_t * value){
	return HAL_I2C_Mem_Read(&hi2c1, ACC_SHIFTED_ADDRESS, (uint8_t)adr, 1, value, 1, 10);
}

#endif /* APPLICATION_USER_LSM303_H_ */
