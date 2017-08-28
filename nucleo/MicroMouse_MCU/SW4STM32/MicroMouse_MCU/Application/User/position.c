/*
 * position.c
 *
 *  Created on: 27 sie 2017
 *      Author: Chupacabra
 */

#include "position.h"

float aXoffset, aYoffset, aZoffset;

I2C_HandleTypeDef * device;
float aX, aY, aZ;
float vX, vY, vZ;
uint32_t lastTime;

inline float dx(uint32_t dt, float x1, float x2){
	return  (x1+x2)*dt/2/1000;
}

bool position_int(I2C_HandleTypeDef * i2c){
	bool control = true;
	aX = 0;
	aY = 0;
	aZ = 0;
	vX = 0;
	vY = 0;
	vZ = 0;
	aXoffset = 0;
	aYoffset = 0;
	aZoffset = 0;
	lastTime = 0;
	control &= LSM303_init(i2c);
	control &= LSM303_enableAccelerometer(rate_25Hz, scale_2g);
	control &= LSM303_axisEnable(axisZ);
	control &= LSM303_axisEnable(axisY);
	control &= LSM303_axisEnable(axisX);
	return control;
}

void position_get(position * pos, uint32_t time){
	uint32_t dt = time - lastTime;
	lastTime = time;

	float newAx, newAy, newAz;

	newAx = LSM303_getAcceleration(axisX) - aXoffset;
	newAy = LSM303_getAcceleration(axisY) - aYoffset;
	newAz = LSM303_getAcceleration(axisZ) - aZoffset;

	pos -> xV += dx(dt, newAx, aX);
	pos -> yV += dx(dt, newAy, aY);
	pos -> zV += dx(dt, newAz, aZ);

	aX = newAx;
	aY = newAy;
	aZ = newAz;

	pos -> x += dx(dt, pos -> xV, vX);
	pos -> y += dx(dt, pos -> yV, vY);
	pos -> z += dx(dt, pos -> zV, vZ);

	vX = pos -> xV;
	vY = pos -> yV;
	vZ = pos -> zV;
}

void position_calibrate(){
	HAL_Delay(1000);
	uint32_t iterations = 128;
	aXoffset = 0;
	aYoffset = 0;
	aZoffset = 0;
	for(uint32_t i =0; i < iterations ; i++){
		aXoffset += LSM303_getAcceleration(axisX);
		aYoffset += LSM303_getAcceleration(axisY);
		aZoffset += LSM303_getAcceleration(axisZ);
		HAL_Delay(50);
	}
	aXoffset /= iterations;
	aYoffset /= iterations;
	aZoffset /= iterations;
}
