/*
 * L293D.h
 *
 *  Created on: 5 cze 2017
 *      Author: Chupacabra
 */

#ifndef _L293D_H_
#define _L293D_H_

#include <stdbool.h>
#include "tim.h"
#include "stm32f4xx_hal.h"

#define L293D_MAX_VOLTAGE 100

typedef struct single_dc{
	TIM_HandleTypeDef *pwm_gen;
	uint32_t channel;
	GPIO_TypeDef * DC_A_Port;
	uint16_t DC_A_Pin;
	GPIO_TypeDef * DC_B_Port;
	uint16_t DC_B_Pin;
}single_dc;

typedef struct l293d{
   	single_dc * left_dc;
	single_dc * right_dc;
}l293d;


bool L293D_init(l293d * myL293D);
bool L293D_stop(single_dc * dc);
bool L293D_setDir(single_dc * dc, int8_t dir);
bool L293D_toggleDir(single_dc * dc);
bool L293D_setVoltage(single_dc * dc, uint16_t speed);
bool L293D_demo(l293d * demo);

#endif /* _L293D_H_ */




