/*
 * test_userInterface.h
 *
 *  Created on: 29 sie 2017
 *      Author: Chupacabra
 */

#ifndef TEST_USERINTERFACE_H_
#define TEST_USERINTERFACE_H_

#include "userInterface.h"
#include <stdbool.h>
#include "usart.h"

bool UI_initTest(UART_HandleTypeDef * device);
bool UI_writeTextTest();
bool UI_writeNumberTest();
bool UI_writeTimeTest();
bool UI_complexTest(UART_HandleTypeDef * device);


#endif /* TEST_USERINTERFACE_H_ */
