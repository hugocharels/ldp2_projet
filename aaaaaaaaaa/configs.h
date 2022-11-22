#ifndef _CONFIGS_H
#define _CONFIGS_H

#include <string>

const std::string LEVEL1 = "levels/board2.txt";
const std::string LEVEL2 = "levels/board3.txt";

constexpr int    windowWidth      = 500;
constexpr int    windowHeight     = 500;
constexpr double refreshPerSecond = 60;

struct Point {
	int x, y;

	bool operator==(Point other) { return x == other.x and y == other.y; }
};


typedef enum { UP, DOWN, LEFT, RIGHT, INVALID } MOVE;

typedef enum { EMPTY = '-', WALL = '#', TARGET = '@', TP = '%', PLAYER = '$', BOX = '&' } CELL;

enum class COLOR { NONE = 1, RED, YELLOW, BLUE, ORANGE, GREEN, PURPLE };

COLOR charToColor(char x);



#endif