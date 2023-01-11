#ifndef _MOVEABLE_CELL_HPP
#define _MOVEABLE_CELL_HPP

#include "Cell.hpp"
#include "../../configs.hpp"


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

	virtual bool walkable() override { return false; }

	// GETTER
	Point getPos() const { return position; }

};

#endif