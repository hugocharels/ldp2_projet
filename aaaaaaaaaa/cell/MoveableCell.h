#ifndef _MOVEABLE_CELL_H
#define _MOVEABLE_CELL_H

#include "Cell.h"
#include "../configs.h"


class Moveable: public virtual Cell {

	Point position;
	int steps=0;

public:

	Moveable(Point pos): Cell('*'), position{pos} {}
	
	~Moveable()=default;

	void move(MOVE movement) {
		if (movement == UP) {position.x--;}
		else if (movement == DOWN) {position.x++;}
		else if (movement == LEFT) {position.y--;}
		else if (movement == RIGHT) {position.y++;}
		this->steps++;
	}

	int getSteps() const { return steps; }

	Point getPos() const { return position; }

};


#endif