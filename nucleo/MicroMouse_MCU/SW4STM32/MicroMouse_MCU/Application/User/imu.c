/*
 * imu.c
 *
 *  Created on: 6 wrz 2017
 *      Author: Marcin Rosenhof
 */

//typedef enum
//{
//  HAL_OK       = 0x00U,
//  HAL_ERROR    = 0x01U,
//  HAL_BUSY     = 0x02U,
//  HAL_TIMEOUT  = 0x03U
//} HAL_StatusTypeDef;
//

#include "imu.h"


HAL_StatusTypeDef imu_init(){
	HAL_StatusTypeDef status;
	uint8_t data;

	// Gyro
	data = 0b00101111;	// Band width=100Hz, cut off=25Hz, power on, xyz enable
	status = gyro_writeReg(gyro_CTRL1, data);
	if(status != HAL_OK){
		return status;
	}
	//Acc
	data = 0b01100111; // Rate=100z, xyz enable, scale =2g
	status = acc_writeReg(acc_CTRL1, data);
	if(status != HAL_OK){
		return status;
	}

	//Magneto
	data = 0b01111100; // Rate=100z, igh resolution, scale=2gauss
	status = acc_writeReg(acc_CTRL5, data);
	if(status != HAL_OK){
		return status;
	}
	data = 0b00000001; // countinous converiosn
	status = acc_writeReg(acc_CTRL7, data);
	if(status != HAL_OK){
		return status;
	}
	return HAL_OK;
}

vector3D imu_getAcceleration(void){
	vector3D a = imu_getGravity();
	vec_mmulti(&a, IMU_GRAVITY);
	return a;
}

vector3D imu_getGravity(void){
	acc_writeReg(acc_CTRL1, 0b01100111);
	vector3D g;
	uint8_t l = 0, h = 0;
	int16_t tmp;

	acc_readReg(acc_OUT_X_L_A, &l);
	acc_readReg(acc_OUT_X_H_A, &h);
	tmp = ( h << 8) + l ;
	g.x = ((float)tmp*ACC_MAX_SCALE)/(float)INT16_MAX;

	acc_readReg(acc_OUT_Y_L_A, &l);
	acc_readReg(acc_OUT_Y_H_A, &h);
	tmp = ( h << 8) + l ;
	g.y = ((float)tmp*ACC_MAX_SCALE)/(float)INT16_MAX;

	acc_readReg(acc_OUT_Z_L_A, &l);
	acc_readReg(acc_OUT_Z_H_A, &h);
	tmp = ( h << 8) + l ;
	g.z = ((float)tmp*ACC_MAX_SCALE)/(float)INT16_MAX;

	return g;
}

vector3D imu_getAngleVelocity(void){
	vector3D wAngle;
	int16_t w = 0;
	uint8_t l = 0, h = 0;

	gyro_readReg(gyro_OUT_X_L, &l);
	gyro_readReg(gyro_OUT_X_H, &h);
	w = ( h << 8) + l ;
	wAngle.x = ((float)w*IMU_GYRO_MAX_DPS)/(float)INT16_MAX;

	gyro_readReg(gyro_OUT_Y_L, &l);
	gyro_readReg(gyro_OUT_Y_H, &h);
	w = ( h << 8) + l ;
	wAngle.y = ((float)w*IMU_GYRO_MAX_DPS)/(float)INT16_MAX;

	gyro_readReg(gyro_OUT_Z_L, &l);
	gyro_readReg(gyro_OUT_Z_H, &h);
	w = ( h << 8) + l ;
	wAngle.z = ((float)w*IMU_GYRO_MAX_DPS)/(float)INT16_MAX;

	return wAngle;
}

vector3D imu_getInduction(void){
	acc_writeReg(acc_CTRL7, 0b00000001);

	vector3D g;
	uint8_t l = 0, h = 0;
	int16_t tmp;

	acc_readReg(acc_OUT_X_L_M, &l);
	acc_readReg(acc_OUT_X_H_M, &h);
	tmp = ( h << 8) + l ;
	g.x = ((float)tmp*MAG_MAX_SCALE)/(float)INT16_MAX;

	acc_readReg(acc_OUT_Y_L_M, &l);
	acc_readReg(acc_OUT_Y_H_M, &h);
	tmp = ( h << 8) + l ;
	g.y = ((float)tmp*MAG_MAX_SCALE)/(float)INT16_MAX;

	acc_readReg(acc_OUT_Z_L_M, &l);
	acc_readReg(acc_OUT_Z_H_M, &h);
	tmp = ( h << 8) + l ;
	g.z = ((float)tmp*MAG_MAX_SCALE)/(float)INT16_MAX;

	return g;
}
