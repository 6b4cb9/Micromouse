/*
 * explorer.h
 *
 *  Created on: 15 wrz 2017
 *      Author: Marcin Rosenhof
 */

#ifndef EXPLORER_H_
#define EXPLORER_H_

#include "stm32f4xx_hal.h"

HAL_StatusTypeDef explorer_int(void);
void explorer_visit(void);
void explorer(void);

#endif /* EXPLORER_H_ */
