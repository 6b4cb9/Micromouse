/*
 * L3GD20H.h
 *
 *  Created on: 15 sie 2017
 *      Author: Chupacabra
 */

#ifndef APPLICATION_USER_L3GD20H_H_
#define APPLICATION_USER_L3GD20H_H_

#include "main.h"
#include "stm32f4xx_hal.h"
#include "i2c.h"
#include "L3GD20H_typedef.h"

typedef struct vector3D{
	float x,y,z;
}vector3D;

uint8_t L3GD20H_Init(I2C_HandleTypeDef * i2c);
uint8_t L3GD20_writeReg(L3GD20H_regAddr adress, uint8_t data);
uint8_t L3GD20_readReg(L3GD20H_regAddr adrdress);
vector3D L3GD20_getAngles(void);

#define L3GD20H_ADDRESS   			0b1101011
#define L3GD20H_SHIFTED_ADDRESS 	(L3GD20H_ADDRESS << 1)
#define MAX_DPS						245.0





#endif /* APPLICATION_USER_L3GD20H_H_ */
