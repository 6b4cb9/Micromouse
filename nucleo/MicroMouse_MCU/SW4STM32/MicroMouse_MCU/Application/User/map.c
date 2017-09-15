/*
 * map.c
 *
 *  Created on: 15 wrz 2017
 *      Author: Marcin Rosenhof
 */
#include "map.h"

Field map[MAP_HIGH][MAP_WIDTH];
Wall vertical[(MAP_HIGH+1)*MAP_WIDTH];
Wall horizontal[(MAP_WIDTH+1)*MAP_HIGH];

void map_init(void){
	for(uint16_t i = 0; i < (MAP_HIGH+1)*MAP_WIDTH; i++ ){
		vertical[i].checked = false;
		vertical[i].builtUp = false;
	}
	for(uint16_t i = 0; i < (MAP_WIDTH+1)*MAP_HIGH; i++ ){
		horizontal[i].checked = false;
		horizontal[i].builtUp = false;
	}

	for(uint8_t col = 0; col < MAP_WIDTH; col++){
		for(uint8_t row = 0; row < MAP_HIGH; row++){
			map[row][col].visited = false;
			map[row][col].north = &(vertical[col+row*MAP_WIDTH]);
			map[row][col].west = &(horizontal[row+col*MAP_HIGH]);
			map[row][col].south = &(vertical[col+(row+1)*MAP_WIDTH]);
			map[row][col].east = &(horizontal[row+(col+1)*MAP_HIGH]);
		}
	}
}

