/*
 * imu.h
 *
 *  Created on: 6 wrz 2017
 *      Author: Chupacabra
 */

//TODO: change &hi2c1 for #define
//TODO: write and read should return status.

#ifndef IMU_H_
#define IMU_H_

#define IMU_GYRO_MAX_DPS		245.0
#define IMU_GRAVITY 			9.81
#define ACC_MAX_SCALE 			2.0
#define MAG_MAX_SCALE 			2.0

#include "vector3D.h"
#include "LSM303.h"
#include  "L3GD20H.h"
#include "stm32f4xx_hal.h"

uint8_t imu_init(void);
vector3D imu_getAcceleration(void);
vector3D imu_getGravity(void);
vector3D imu_getAngleVelocity(void);
vector3D imu_getInduction(void);


#endif /* IMU_H_ */
