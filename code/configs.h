#ifndef _CONFIGS_H
#define _CONFIGS_H


typedef struct {
	int x, y;
} Point;

bool Point::operator==(Point other) {
	return x == other.x and y == other.y;
}


typedef enum {EMPTY = '0', WALL = '#', TARGET = '¤'} CELL;

typedef enum { UP, DOWN, RIGHT, LEFT} MOVE;


template<typename T>
contains(T &contener, Point &pos) {
	for (auto &i : contener) {
		if (pos == i.getPos()) {
			return true;
		}
	}
	return false;
}


#endif