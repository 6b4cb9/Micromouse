/*
 * imu.h
 *
 *  Created on: 6 wrz 2017
 *      Author: Chupacabra
 */

#ifndef IMU_H_
#define IMU_H_

#include "vector3D.h"
#include "LSM303_typedef.h"
#include  "L3GD20H.h"
#include "stm32f4xx_hal.h"

uint8_t imu_init(I2C_HandleTypeDef * i2c);
vector3D imu_getAcceleration(void);
vector3D imu_getGravity(void);
vector3D imu_getAngleVelocity(void);
vector3D imu_getInduction(void);


#endif /* IMU_H_ */
