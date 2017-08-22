/*
 * LSM303.h
 *
 *  Created on: 22 sie 2017
 *      Author: Chupacabra
 */

#ifndef APPLICATION_USER_LSM303_H_
#define APPLICATION_USER_LSM303_H_

#include <stdbool.h>
#include "stm32f4xx_hal.h"

#define LSM303_ACC_ADDRESS 				0b0011001
#define LSM303_ACC_SHIFTED_ADDRESS		(1<<LSM303_ACC_ADDRESS)

typedef enum LSM303_regAddr
{
  TEMP_OUT_L        = 0x05,
  TEMP_OUT_H        = 0x06,

  STATUS_M          = 0x07,

  INT_CTRL_M        = 0x12,
  INT_SRC_M         = 0x13,
  INT_THS_L_M       = 0x14,
  INT_THS_H_M       = 0x15,

  OFFSET_X_L_M      = 0x16,
  OFFSET_X_H_M      = 0x17,
  OFFSET_Y_L_M      = 0x18,
  OFFSET_Y_H_M      = 0x19,
  OFFSET_Z_L_M      = 0x1A,
  OFFSET_Z_H_M      = 0x1B,
  REFERENCE_X       = 0x1C,
  REFERENCE_Y       = 0x1D,
  REFERENCE_Z       = 0x1E,

  CTRL0             = 0x1F,
  CTRL1             = 0x20,
  CTRL2             = 0x21,
  CTRL3             = 0x22,
  CTRL4             = 0x23,
  CTRL5             = 0x24,
  CTRL6             = 0x25,
  CTRL7             = 0x26,
  STATUS_A          = 0x27,

  OUT_X_L_A         = 0x28,
  OUT_X_H_A         = 0x29,
  OUT_Y_L_A         = 0x2A,
  OUT_Y_H_A         = 0x2B,
  OUT_Z_L_A         = 0x2C,
  OUT_Z_H_A         = 0x2D,

  FIFO_CTRL         = 0x2E,
  FIFO_SRC          = 0x2F,

  IG_CFG1           = 0x30,
  IG_SRC1           = 0x31,
  IG_THS1           = 0x32,
  IG_DUR1           = 0x33,
  IG_CFG2           = 0x34,
  IG_SRC2           = 0x35,
  IG_THS2           = 0x36,
  IG_DUR2           = 0x37,

  CLICK_CFG         = 0x38,
  CLICK_SRC         = 0x39,
  CLICK_THS         = 0x3A,
  TIME_LIMIT        = 0x3B,
  TIME_LATENCY      = 0x3C,
  TIME_WINDOW       = 0x3D,

  Act_THS           = 0x3E,
  Act_DUR           = 0x3F,

  CRA_REG_M         = 0x00,
  CRB_REG_M         = 0x01,
  MR_REG_M          = 0x02,

  SR_REG_M          = 0x09,
  IRA_REG_M         = 0x0A,
  IRB_REG_M         = 0x0B,
  IRC_REG_M         = 0x0C,

  WHO_AM_I          = 0x0F,

  TEMP_OUT_H_M      = 0x31,
  TEMP_OUT_L_M      = 0x32,
}LSM303_regAddr;

bool LSM303_writeReg(LSM303_regAddr);
LSM303_regAddr LSM303_readReg();

bool LSM303_initMagnetometr();
bool LSM303_initAccelerometer();

bool LSM303_magDemo();
bool LSM303_accDemo();

bool LSM303_getAcc();
bool LSM303_getMag();

typedef struct LSM303_position{
	uint32_t x;
	uint32_t y;
	uint32_t z;
}LSM303_position;

typedef struct LSM303{
	LSM303_position magnetometer;
	LSM303_position accelerometer;
	I2C_HandleTypeDef * i2c;
}LSM303;


#endif /* APPLICATION_USER_LSM303_H_ */
