#ifndef _CONFIGS_H
#define _CONFIGS_H

typedef struct {
	int x;
	int y;
} Point;


typedef enum {EMPTY = '0', WALL = '#', TARGET = '¤'} CELL;


class Moveable {

	Point position;

public:

	Moveable(Point pos):position{pos} {}
	~Moveable()=default;

	void move(Point &pos) {
		this->position.x = pos.x;
		this->position.y = pos.y;
	}

};

#endif