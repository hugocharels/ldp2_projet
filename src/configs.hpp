#ifndef _CONFIGS_HPP
#define _CONFIGS_HPP

#include "include.hpp"


// CONST
constexpr int    WINDOW_WIDTH       = 900;
constexpr int    WINDOW_HEIGHT      = 600;
constexpr int 	 CELL_SIZE          = 50; 
constexpr double REFRESH_PER_SECOND = 30;
constexpr int    TIME_IN_WELCOME    = 2;
constexpr int    TEXT_SIZE          = 20;
constexpr int    MAX_STEP_LIMIT     = 120;

// POINT
struct Point {
	int x=0, y=0;
	bool operator==(Point other) { return x == other.x and y == other.y; }
};


// ENUM
enum class MOVE { UP, DOWN, LEFT, RIGHT, INVALID };
enum class CELL { EMPTY = '-', WALL = '#', TARGET = '@', TP = '%', PLAYER = '$', BOX = '&' };
enum class COLOR { NONE = 1, RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE, PINK };
enum class GAME_STATE { WELCOME, EDITOR, INGAME, ENDGAME };


// FUNCTIONS
COLOR charToColor(char x);
COLOR intToColor(int x);
char ColorToNum(COLOR color);
char ColorToLetter(COLOR color);

int mod(int x, int y);

#endif