#ifndef _CONFIGS_H
#define _CONFIGS_H

#include <string>

const std::string LEVEL1 = "levels/board2.txt";
const std::string LEVEL2 = "levels/board3.txt";

constexpr int    windowWidth      = 1000;
constexpr int    windowHeight     = 600;
constexpr int 	 cellSize         = 50; 
constexpr double refreshPerSecond = 1;

struct Point {
	int x, y;

	bool operator==(Point other) { return x == other.x and y == other.y; }
};


typedef enum { UP, DOWN, LEFT, RIGHT, INVALID } MOVE;

typedef enum { EMPTY = '-', WALL = '#', TARGET = '@', TP = '%', PLAYER = '$', BOX = '&' } CELL;

enum class COLOR { NONE = 1, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, PINK };

COLOR charToColor(char x);

#endif