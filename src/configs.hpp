#ifndef _CONFIGS_HPP
#define _CONFIGS_HPP

#include "include.hpp"


// CONST
constexpr int    windowWidth      = 900;
constexpr int    windowHeight     = 600;
constexpr int 	 cellSize         = 50; 
constexpr double refreshPerSecond = 30;


// POINT
struct Point {
	int x=0, y=0;
	bool operator==(Point other) { return x == other.x and y == other.y; }
};


// ENUM
typedef enum { UP, DOWN, LEFT, RIGHT, INVALID } MOVE;
typedef enum { EMPTY = '-', WALL = '#', TARGET = '@', TP = '%', PLAYER = '$', BOX = '&' } CELL;
enum class COLOR { NONE = 1, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, PINK };
enum class GAME_STATE { WELCOME, PLAY, EDITOR, WON, LOST };


// FUNCTIONS
COLOR charToColor(char x);
COLOR intToColor(int x);
int mod(int x, int y);


#endif