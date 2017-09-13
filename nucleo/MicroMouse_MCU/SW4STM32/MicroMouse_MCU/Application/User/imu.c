/*
 * imu.c
 *
 *  Created on: 6 wrz 2017
 *      Author: Chupacabra
 */
#include "imu.h"

#define MAX_DPS 1000

I2C_HandleTypeDef * device = 0;

uint8_t imu_init(I2C_HandleTypeDef * i2c){
	//module init
	if(device == 0){
		return 1;
	}
	device = i2c;
	uint8_t data;

	// Gyro
	data = 0b00101111;	// Band width=100Hz, cut off=25Hz, power on, xyz enable
	L3GD20H_writeReg(L3GD20H_CTRL1, data);

	//Acc


	//Magneto

	return 0;

}

vector3D imu_getAcceleration(void){

}

vector3D imu_getGravity(void){

}

vector3D imu_getAngleVelocity(void){
	vector3D wAngle;
	int16_t w = 0;
	uint8_t l = 0, h = 0;

	l = L3GD20H_readReg(L3GD20H_OUT_X_L);
	h = L3GD20H_readReg(L3GD20H_OUT_X_H);
	w = ( h << 8) + l ;
	wAngle.x = ((float)w*MAX_DPS)/(float)INT16_MAX;

	l = L3GD20H_readReg(L3GD20H_OUT_Y_L);
	h = L3GD20H_readReg(L3GD20H_OUT_Y_H);
	w = ( h << 8) + l ;
	wAngle.y = ((float)w*MAX_DPS)/(float)INT16_MAX;

	l = L3GD20H_readReg(L3GD20H_OUT_Z_L);
	h = L3GD20H_readReg(L3GD20H_OUT_Z_H);
	w = ( h << 8) + l ;
	wAngle.z = ((float)w*MAX_DPS)/(float)INT16_MAX;

	return wAngle;
}

vector3D imu_getInduction(void){

}
