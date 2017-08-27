/*
 * position.c
 *
 *  Created on: 27 sie 2017
 *      Author: Chupacabra
 */

#include "position.h"

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
	lastTime = 0;
	control &= LSM303_init(i2c);
	control &= LSM303_enableAccelerometer(rate_200Hz, scale_2g);
	control &= LSM303_axisEnable(axisZ);
	control &= LSM303_axisEnable(axisY);
	control &= LSM303_axisEnable(axisX);
	return control;
}

void position_get(position * pos, uint32_t time){
	uint32_t dt = time - lastTime;
	lastTime = time;

	float newAx, newAy, newAz;

	newAx = LSM303_getAcceleration(axisX);
	newAy = LSM303_getAcceleration(axisY);
	newAz = LSM303_getAcceleration(axisZ);

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
