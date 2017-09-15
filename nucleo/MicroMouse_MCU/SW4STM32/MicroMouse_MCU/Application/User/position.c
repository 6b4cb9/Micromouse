/*
 * position.c
 *
 *  Created on: 15 wrz 2017
 *      Author: Marcin Rosenhof
 */
#include "position.h"

vector3D w, g, mag;

HAL_StatusTypeDef pos_init(){
	HAL_StatusTypeDef status;

	status = imu_init();
	if(status != HAL_OK){
			return status;
	}

	return HAL_OK;
}
HAL_StatusTypeDef pos_calculate(){
	 w = imu_getAngleVelocity();
	 g = imu_getGravity();
	 mag = imu_getInduction();

	 return HAL_OK;
}

