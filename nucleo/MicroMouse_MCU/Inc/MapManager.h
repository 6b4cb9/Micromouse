/*
  * MapManager.h
  *
  *  Created on: 06.09.2017
  *      Author: Pawed
  */

#ifndef APPLICATION_USER_MAPMANAGER_H_
#define APPLICATION_USER_MAPMANAGER_H_

#include <stdbool.h>

#define ARRAY_WIDITH 10
#define ARRAY_HEIGHT 10

typedef struct cellStructure{
	bool isVisited;
	bool leftSideFlag;
	bool rightSideFlag;
	bool upperSideFlag;
	bool lowerSideFlag;
}cellStructure;

cellStructure labirynthMap[ARRAY_HEIGHT][ARRAY_WIDITH];

void MapManager_init();
void MapManager_visit(cellStructure* arrayElement,float source_directory);


#endif /* APPLICATION_USER_MAPMANAGER_H_ */
