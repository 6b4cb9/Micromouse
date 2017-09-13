/*
 * test_userInterface.c
 *
 *  Created on: 29 sie 2017
 *      Author: Chupacabra
 */
#include "test_userInterface.h"

UART_HandleTypeDef * device;

bool UI_initTest(UART_HandleTypeDef * d){
	// init with zero value
	device = d;
	if(ui_init(0) == false){
		char m[] = "Initialization with zero value passed.\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Initialization with zero value failed.\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}

	// int with ok value
	if(ui_init(0) == true){
		char m[] = "Initialization with UART_HandleTypeDef passed.\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Initialization with UART_HandleTypeDef failed.\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}

	return true;
}

bool UI_writeTextTest(){
	//write empty string

	//write simple text

	//write long text with \n , \t etc.
	return false;
}

bool UI_writeNumberTest(){
	//write text
	if(ui_writeNumber('a')){
		char m[] = "Converting car to number succeed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Converting car to number failed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}

	//write zero
	if(ui_writeNumber(0)){
		char m[] = "Writing zero succeed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Writing zero failed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}
	//write 8-bit positive value
	if(ui_writeNumber(125)){
		char m[] = "Writing 125 succeed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Writing 125 failed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}
	//write 32-bit positive value
	if(ui_writeNumber(123456)){
		char m[] = "Writing 123456 succeed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Writing 123456 failed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}
	//write 8-bit negativ value
	if(ui_writeNumber(-32)){
		char m[] = "Writing -32 succeed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Writing -32 failed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}
	//write 32-bit negative value
	if(ui_writeNumber(-123456789)){
		char m[] = "Writing -123456789 succeed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
	}else{
		char m[] = "Writing -123456789 failed!\n\r";
		HAL_UART_Transmit(device, (uint8_t *)m, sizeof(m), 100);
		return false;
	}
	return true;
}

bool UI_writeTimeTest(){
	// negative value tiem

	//zero time

	//only seconds

	//only minutes

	//only houers

	//random time
	return false;
}

bool UI_complexTest(UART_HandleTypeDef * device){
	if(!UI_initTest(device)){
		return false;
	}
	if(!UI_writeTextTest()){
		return false;
	}
	if(!UI_writeNumberTest()){
		return false;
	}
	if(!UI_writeTimeTest()){
		return false;
	}
	return true;
}
