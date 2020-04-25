/*
 * MapManager.c
 *
 *  Created on: 06.09.2017
 *      Author: Pawed
 */
#include "MapManager.h"
#include "wallSensor.h"
#include <stdbool.h>
#include <stdint.h>


void MapManager_init(){

	for(uint8_t i = 0; i< ARRAY_HEIGHT; i++){
		for(uint8_t j = 0; j< ARRAY_WIDITH; j++){
			labirynthMap[i][j].isVisited=false;
			labirynthMap[i][j].leftSideFlag=false;
			labirynthMap[i][j].rightSideFlag=false;
			labirynthMap[i][j].upperSideFlag=false;
			labirynthMap[i][j].lowerSideFlag=false;
			}

	}

}
void MapManager_visit(cellStructure* arrayElement,float source_directory){
	if(arrayElement->isVisited == false){
		WallSensor* wallSensor;
		sensor_calculate(&wallSensor);
		if(source_directory == 0){
			if(wallSensor->walls[0] == 0xFF){
				arrayElement->leftSideFlag=true;
			}
			if(wallSensor->walls[1] == 0xFF && wallSensor->walls[2] == 0xFF){
				arrayElement->upperSideFlag=true;
			}
			if(wallSensor->walls[3] == 0xFF){
				arrayElement->rightSideFlag=true;
			}
		}
		else if(source_directory == 1){
			if(wallSensor->walls[0] == 0xFF){
				arrayElement->lowerSideFlag=true;
			}
			if(wallSensor->walls[1] == 0xFF && wallSensor->walls[2] == 0xFF){
				arrayElement->leftSideFlag=true;
			}
			if(wallSensor->walls[3] == 0xFF){
				arrayElement->upperSideFlag=true;
			}
		}
		else if(source_directory == 2){
			if(wallSensor->walls[0] == 0xFF){
				arrayElement->rightSideFlag=true;
			}
			if(wallSensor->walls[1] == 0xFF && wallSensor->walls[2] == 0xFF){
				arrayElement->lowerSideFlag=true;
			}
			if(wallSensor->walls[3] == 0xFF){
				arrayElement->leftSideFlag=true;
			}
		}
		else if(source_directory == 3){
			if(wallSensor->walls[0] == 0xFF){
				arrayElement->upperSideFlag=true;
			}
			if(wallSensor->walls[1] == 0xFF && wallSensor->walls[2] == 0xFF){
				arrayElement->rightSideFlag=true;
			}
			if(wallSensor->walls[3] == 0xFF){
				arrayElement->lowerSideFlag=true;
			}
		}

	}



}
