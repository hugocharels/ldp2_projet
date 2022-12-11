#ifndef _MOVEABLE_CELL_H
#define _MOVEABLE_CELL_H

#include "Cell.h"
#include "../configs.h"


class MoveableCell: public virtual Cell {

protected:
	Point position;

public:

	MoveableCell(CELL cell, Point pos): Cell(cell), position{pos} {}
	
	~MoveableCell()=default;

	virtual void move(MOVE movement) {
		if (movement == UP) {position.x--;}
		else if (movement == DOWN) {position.x++;}
		else if (movement == LEFT) {position.y--;}
		else if (movement == RIGHT) {position.y++;}
	}

	Point getPos() const { return position; }

	virtual bool walkable() override { return false; }
};


#endif