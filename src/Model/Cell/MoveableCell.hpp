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
		switch (movement) { 
			case MOVE::UP: position.x--; break;
			case MOVE::DOWN: position.x++; break;
			case MOVE::LEFT: position.y--; break;
			case MOVE::RIGHT: position.y++; break;
			default: break;
		}
	}

	virtual bool walkable() override { return false; }

	// GETTER
	Point getPos() const { return position; }

};

#endif