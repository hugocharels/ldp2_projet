#ifndef _CONFIGS_H
#define _CONFIGS_H


struct Point {

	int x, y;

	bool operator==(Point other) { return x == other.x and y == other.y; }
};


typedef enum { UP, DOWN, LEFT, RIGHT, INVALID} MOVE;


#endif