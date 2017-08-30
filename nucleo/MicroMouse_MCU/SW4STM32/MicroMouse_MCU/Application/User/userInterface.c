/*
 * userInterface.c
 *
 *  Created on: 29 sie 2017
 *      Author: Chupacabra
 */

#include "userInterface.h"

UART_HandleTypeDef * ui_device;

bool ui_init(UART_HandleTypeDef * uart){
	if(uart == 0){
		return false;
	}
	ui_device = uart;
	return true;
}
