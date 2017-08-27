/*
 * position.h
 *
 *  Created on: 27 sie 2017
 *      Author: Chupacabra
 */

#ifndef POSITION_H_
#define POSITION_H_

#include "LSM303.h"

typedef struct position{
	float x, y, z;
	float xV, yV, zV;
	uint16_t yaw, pitch, roll;
	uint16_t yawW, pitchW, rollW;
}position;

bool position_int(I2C_HandleTypeDef *i2c);
void position_get(position * pos, uint32_t time);

#endif /* POSITION_H_ */
