/*
 * wallSensor.h
 *
 *  Created on: 6 maj 2017
 *      Author: Chupacabra
 */

#ifndef APPLICATION_USER_WALLSENSOR_H_
#define APPLICATION_USER_WALLSENSOR_H_

#include <stdbool.h>
#include "stm32f4xx_hal.h"


#define NUM_OF_SENSORS 2
#define MAX_THRESHOLD 3072
#define TOLERANCE 100

typedef struct WallSensor{

	ADC_HandleTypeDef sensor_adc;
	uint16_t sensor_measurment[NUM_OF_SENSORS];
	uint16_t sensor_threshold[NUM_OF_SENSORS];
	uint8_t walls[NUM_OF_SENSORS];
	uint8_t angle;

}WallSensor;

bool sensor_calibrate(WallSensor * sens, int8_t channel, uint16_t it_num);
bool sensor_init(WallSensor * sens);
bool sensor_calculate(WallSensor * sens);

#endif /* APPLICATION_USER_WALLSENSOR_H_ */
