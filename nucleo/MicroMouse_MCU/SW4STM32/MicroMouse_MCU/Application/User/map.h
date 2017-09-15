/*
 * map.h
 *
 *  Created on: 15 wrz 2017
 *      Author: Marcin Rosenhof
 */

#ifndef MAP_H_
#define MAP_H_

#define MAP_WIDTH		3
#define MAP_HIGH		3


#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef struct{
	bool checked;
	bool builtUp;
}Wall;

typedef struct{
	Wall * north;
	Wall * west;
	Wall * south;
	Wall * east;
	bool visited;
}Field;

void map_init(void);



#endif /* MAP_H_ */
