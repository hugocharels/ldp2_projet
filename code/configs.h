#ifndef _CONFIGS_H
#define _CONFIGS_H

#include <string>


const std::string FILE_TEST = "test_board.txt";



struct Point {
	int x, y;
	bool operator==(Point other) {
		return x == other.x and y == other.y;
	}

};


typedef enum {EMPTY = ' ', WALL = '#', TARGET = '@'} CELL;

typedef enum { UP, DOWN, RIGHT, LEFT, INVALID} MOVE;


#endif