/*
 * position.h
 *
 *  Created on: 15 wrz 2017
 *      Author: Marcin Rosenhof
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "stm32f4xx_hal.h"
#include "imu.h"
#include "vector3D.h"

float x, y, yaw;

HAL_StatusTypeDef pos_init(void);
HAL_StatusTypeDef pos_calculate();




#endif /* POSITION_H_ */
