#ifndef _CONFIGS_H_
#define _CONFIGS_H_

typedef struct {
	int x;
	int y;
} Point;


typedef enum {EMPTY = '0', WALL = '#', BOX = '$', PLAYER = 'P', TARGET = '¤'} CELL;


#endif