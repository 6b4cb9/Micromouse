/*
 * wallSensor.c
 *
 *  Created on: 6 maj 2017
 *      Author: Chupacabra
 */

#include "wallSensor.h"

bool sensor_calibrate(WallSensor * sens, int8_t channel, uint16_t it_num){
	if(channel >= NUM_OF_SENSORS){
		return false;
	}
	bool flag = true;
	uint32_t tmp[NUM_OF_SENSORS];
	for(uint8_t i = 0; i < NUM_OF_SENSORS; i++){
		tmp[i] = 0;
	}
	for(uint16_t i = 0; i < it_num ; i++){
		for(uint8_t j=0 ; j < NUM_OF_SENSORS; j++){
			tmp[j] += sens->sensor_measurment[j];
		}
		HAL_Delay(5);
	}
	for(uint8_t i = 0 ; i< NUM_OF_SENSORS ; i++){
		if(channel == -1 || i == channel){
			sens->sensor_threshold[i] = tmp[i]/it_num;
			if(sens->sensor_threshold[i] > MAX_THRESHOLD){
				flag = false;
			}
		}
	}
	return flag;
}

bool sensor_init(WallSensor * sens){
	HAL_ADC_Start_DMA(&(sens->sensor_adc), sens->sensor_measurment, NUM_OF_SENSORS);
	for(uint8_t i =0 ; i < NUM_OF_SENSORS; i++){
		sens->walls[i] = 0;
	}
	sens->angle = 0;
	sensor_calibrate(sens, -1, 64);
	return true;
}

bool sensor_calculate(WallSensor * sens){
	for(uint8_t i = 0 ; i < NUM_OF_SENSORS ; i++){
		if(sens->sensor_measurment[i] > sens->sensor_threshold[i] + TOLERANCE)
			sens->walls[i] = 0xFF;
		else
			sens->walls[i] = 0;
	}
	//TODO angle calculate
	sens->angle=0;
	return true;
}

