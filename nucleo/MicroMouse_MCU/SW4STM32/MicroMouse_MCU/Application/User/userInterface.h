/*
 * userInterface.h
 *
 *  Created on: 29 sie 2017
 *      Author: Chupacabra
 */

#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_

#include <stdbool.h>
#include  "usart.h"
#include "string.h"
#include<stdlib.h>

#define UI_TIMEOUT 10

extern UART_HandleTypeDef * ui_device;

bool ui_init(UART_HandleTypeDef * uart);


inline bool ui_writeText(char * str){
	bool ans = HAL_UART_Transmit(ui_device, str, strlen(str), UI_TIMEOUT);
	return ans;
}

inline bool ui_writeNumber(int num){
	char str[11];
	sprintf(str, "%d", num);
	bool ans = HAL_UART_Transmit(ui_device, str, strlen(str), UI_TIMEOUT);
	return ans;
}

inline bool ui_writeTime(unsigned int time){
	int ms = time % 1000;
	time /= 1000;
	int s = time % 60;
	time /= 60;
	int min = time % 60;
	time /= 60; //time is in hours now.

	if(time > 1000){
		time = 0;
		//TODO It should be better overflow control.
	}

	char cms[4];
	sprintf(cms, "%d", ms);
	char cs[3];
	sprintf(cs, "%d", s);
	char cmin[3];
	sprintf(cmin, "%d", min);
	char ch[20];
	sprintf(ch, "%d", time);

	strcat(ch, ":");
	strcat(ch, cmin);
	strcat(ch, ":");
	strcat(ch, cs);
	strcat(ch, ",");
	strcat(ch, cms);
	bool ans = HAL_UART_Transmit(ui_device, ch, strlen(ch), UI_TIMEOUT);
	return ans;
}

inline bool ui_writeFloat(float num){
	ui_writeText("\n\r");
	int flor = (int)num;
	int friction = abs((int)(100 * num) % 100);
	char c[20];
	sprintf(c, "%d", flor);
	char cfric[3];
	sprintf(cfric, "%d", friction);
	strcat(c, ",");
	if(strlen(cfric)==1){
		 strcat(c, "0");
	}
	strcat(c, cfric);
	bool ans = HAL_UART_Transmit(ui_device, c, strlen(c), UI_TIMEOUT);
	return ans;
}

#endif /* USERINTERFACE_H_ */
