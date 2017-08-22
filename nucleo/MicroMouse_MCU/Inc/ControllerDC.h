/*
 * ControllerDC.h
 *
 *  Created on: 19.08.2017
 *      Author: Pawel
 */

#ifndef APPLICATION_USER_CONTROLLERDC_H_
#define APPLICATION_USER_CONTROLLERDC_H_
#include "L293D.h"

bool ControllerDC_init(l293d * demo);
bool ControllerDC_setSpeed(uint16_t speed,single_dc * demo);
void ControllerDC_break(l293d * demo,int8_t dcIndicator);
bool ControllerDC_demo(l293d * demo);
#endif /* APPLICATION_USER_CONTROLLERDC_H_ */
