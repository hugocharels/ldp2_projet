#ifndef _CONFIGS_H
#define _CONFIGS_H


constexpr int    windowWidth      = 500;
constexpr int    windowHeight     = 500;
constexpr double refreshPerSecond = 60;



struct Point {

	int x, y;

	bool operator==(Point other) { return x == other.x and y == other.y; }
};


typedef enum { UP, DOWN, LEFT, RIGHT, INVALID } MOVE;


#endif