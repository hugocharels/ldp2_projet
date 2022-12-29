#ifndef _CELL_HPP
#define _CELL_HPP

#include "../../configs.hpp"


class Cell {

	CELL type;

public:

	Cell(CELL type):type{type} {}
	virtual ~Cell()=default;

	bool operator==(CELL cell) { return type == cell; }

	char getType() const { return type; }

	virtual bool walkable() { return type==EMPTY; }

};

#endif