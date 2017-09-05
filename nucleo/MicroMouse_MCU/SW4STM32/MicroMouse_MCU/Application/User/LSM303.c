/*
 * LSM303.c
 *
 *  Created on: 22 sie 2017
 *      Author: Chupacabra
 */

#include "LSM303.h"


I2C_HandleTypeDef  * device;
float accelerometerMaxScale;
float magnetometrMaxSale;

bool LSM303_init(I2C_HandleTypeDef *i2c){
	if(i2c == 0){
		return false;
	}
	device = i2c;
	return true;
}

bool LSM303_writeReg(LSM303_regAddr adr, uint8_t value){
	uint8_t address = (uint8_t)adr;
	HAL_I2C_Mem_Write(device, LSM303_ACC_SHIFTED_ADDRESS, address, 1, &value, 1, 10);
	return true;
}

uint8_t LSM303_readReg(LSM303_regAddr adr){
	uint8_t value = 0;
	uint8_t address = adr;
	HAL_I2C_Mem_Read(device, LSM303_ACC_SHIFTED_ADDRESS, address, 1, &value, 1, 10);
	return value;
}

uint8_t LSM303_whoAmI(void){
	// The name should be 0b01001001
	uint8_t name = 0;
	name = LSM303_readReg(WHO_AM_I);
	return name;
}

bool LSM303_reset(){
	bool status;
	uint8_t settings = (1<<7); // BOOT bit
	status = LSM303_writeReg(CTRL0, settings);
	return status;
}

bool LSM303_enableAccelerometer(LSM303_rate rate, LSM303_accelerationFullScale scale){
	uint8_t reg = LSM303_readReg(CTRL1);
	reg |= (rate << 4);
	bool control = LSM303_writeReg(CTRL1, reg);

	reg = LSM303_readReg(CTRL2);
	reg |= (scale << 3);
	if (scale == scale_16g){
		accelerometerMaxScale = 16.0;
	}else{
		accelerometerMaxScale = 2 * scale + 2;
	}
	control &= LSM303_writeReg(CTRL2, reg);
	return control;
}

bool LSM303_axisEnable(LSM303_axes axis){
	uint8_t reg = LSM303_readReg(CTRL1);
	reg |= (1 << axis);
	bool control = LSM303_writeReg(CTRL1, reg);
	return control;
}

bool LSM303_axiesDisable(LSM303_axes axis){
	uint8_t reg = LSM303_readReg(CTRL1);
	reg &= ~(1 << axis);
	bool control = LSM303_writeReg(CTRL1, reg);
	return control;
}

float LSM303_getAcceleration(LSM303_axes axis){
	int16_t a = 0;
	uint8_t l = 0, h = 0;
	float ans;
	switch(axis){
	case axisX:
		l = LSM303_readReg(OUT_X_L_A);
		h = LSM303_readReg(OUT_X_H_A);
		break;
	case axisY:
		l = LSM303_readReg(OUT_Y_L_A);
		h = LSM303_readReg(OUT_Y_H_A);
		break;
	case axisZ:
		l = LSM303_readReg(OUT_Z_L_A);
		h = LSM303_readReg(OUT_Z_H_A);
		break;
	}
	a = ( h << 8) + l ;
	ans = ((float)a*accelerometerMaxScale)/(float)INT16_MAX*LSM303_GRAVITY;
	return ans;
}

bool LSM303_startSelfTest(){
	uint8_t value = LSM303_readReg(CTRL2);
	value |= 0x02;
	return LSM303_writeReg(CTRL2, value);
}

bool LSM303_endSelfTest(){
	uint8_t value = LSM303_readReg(CTRL2);
	value &= ~(0x02);
	return LSM303_writeReg(CTRL2, value);
}

bool LSM303_enableMagnetometer(LSM303_magneticRate rate, LSM303_magnetometerFullScale scale){
	uint8_t reg = LSM303_readReg(CTRL5);
	reg |= ((rate << 2) | 0x60); // high resolution mode

	reg = 0x64;
	bool control = LSM303_writeReg(CTRL5, reg);
	magnetometrMaxSale = 0;
	magnetometrMaxSale += (int)(2 << scale);
	if (scale == scale_12gauss){
		magnetometrMaxSale = 12.0;
	}
	reg = (scale << 5);

	reg = 0x20;
	control &= LSM303_writeReg(CTRL6, reg);
	reg = LSM303_readReg(CTRL7);
	reg &= ~(0x03);

	reg = 0x00;
	control &= LSM303_writeReg(CTRL7, reg);
	return control;
}

float LSM303_getInduction(LSM303_axes axis){
	int16_t a = 0;
		uint8_t l = 0, h = 0;
		float ans;
		switch(axis){
		case axisX:
			l = LSM303_readReg(OUT_X_L_M);
			h = LSM303_readReg(OUT_X_H_M);
			break;
		case axisY:
			l = LSM303_readReg(OUT_Y_L_M);
			h = LSM303_readReg(OUT_Y_H_M);
			break;
		case axisZ:
			l = LSM303_readReg(OUT_Z_L_M);
			h = LSM303_readReg(OUT_Z_H_M);
			break;
		}
		a = ( h << 8) + l ;
		ans = ((float)a*magnetometrMaxSale)/(float)INT16_MAX;
		return ans;
}

