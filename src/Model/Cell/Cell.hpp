#ifndef _CELL_HPP
#define _CELL_HPP

#include "../../configs.hpp"


class Cell {

	CELL type;

public:

	Cell(CELL type):type{type} {}
	virtual ~Cell()=default;

	bool operator==(CELL cell) { return type == cell; }
	virtual bool walkable() { return type==CELL::EMPTY; }

	// GETTER
	CELL getType() const { return type; }

};

#endif