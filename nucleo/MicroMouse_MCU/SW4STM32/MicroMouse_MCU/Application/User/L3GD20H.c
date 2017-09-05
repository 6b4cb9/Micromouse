/*
 * LSM6DS33.c
 *
 *  Created on: 15 sie 2017
 *      Author: Chupacabra
 */

#include "L3GD20H.h"

I2C_HandleTypeDef * device = 0;

uint8_t L3GD20H_writeReg(L3GD20H_regAddr adr, uint8_t value){
	uint8_t address = (uint8_t)adr;
	HAL_I2C_Mem_Write(device, L3GD20H_SHIFTED_ADDRESS, address, 1, &value, 1, 10);
	return 0;
}

uint8_t L3GD20H_readReg(L3GD20H_regAddr adr){
	uint8_t value = 0;
	uint8_t address = adr;
	HAL_I2C_Mem_Read(device, L3GD20H_SHIFTED_ADDRESS, address, 1, &value, 1, 10);
	return value;
}

uint8_t L3GD20H_Init(I2C_HandleTypeDef * i2c){
	if(device == 0){
		return 1;
	}
	device = i2c;

	uint8_t data;

	data = 0b00101111;	// Band width=100Hz, cut off=25Hz, power on, xyz enable
	L3GD20H_writeReg(L3GD20H_CTRL1, data);

	return 0;
}

vector3D L3GD20_getAngles(){
	vector3D angle;
	int16_t w = 0;
	uint8_t l = 0, h = 0;

	l = L3GD20H_readReg(L3GD20H_OUT_X_L);
	h = L3GD20H_readReg(L3GD20H_OUT_X_H);
	w = ( h << 8) + l ;
	angle.x = ((float)w*MAX_DPS)/(float)INT16_MAX;

	l = L3GD20H_readReg(L3GD20H_OUT_Y_L);
	h = L3GD20H_readReg(L3GD20H_OUT_Y_H);
	w = ( h << 8) + l ;
	angle.y = ((float)w*MAX_DPS)/(float)INT16_MAX;

	l = L3GD20H_readReg(L3GD20H_OUT_Z_L);
	h = L3GD20H_readReg(L3GD20H_OUT_Z_H);
	w = ( h << 8) + l ;
	angle.z = ((float)w*MAX_DPS)/(float)INT16_MAX;

	return angle;
}


