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
#include "LSM303_typedef.h"
#include "i2c.h"

#define LSM303_ACC_ADDRESS 				0b0011101
#define LSM303_ACC_SHIFTED_ADDRESS		(LSM303_ACC_ADDRESS << 1)
#define LSM303_GRAVITY 					9.81

bool LSM303_init(I2C_HandleTypeDef *i2c);
bool LSM303_writeReg(LSM303_regAddr, uint8_t);
uint8_t LSM303_readReg(LSM303_regAddr);
uint8_t LSM303_whoAmI(void);
bool LSM303_reset();


bool LSM303_enableAccelerometer(LSM303_rate, LSM303_accelerationFullScale);
bool LSM303_axisEnable(LSM303_axes);
bool LSM303_axiesDisable(LSM303_axes);
float LSM303_getAcceleration(LSM303_axes);

//Temperature feedback.
bool LSM303_tempEnable(void);
bool LSM303_tempDisenable(void);
uint16_t LSM303_getTemp(void);

//self test
bool LSM303_startSelfTest(void);
bool LSM303_endSelfTest(void);

bool LSM303_enableMagnetometer(LSM303_magneticRate, LSM303_magnetometerFullScale);
float LSM303_getInduction(LSM303_axes);

#endif /* APPLICATION_USER_LSM303_H_ */
