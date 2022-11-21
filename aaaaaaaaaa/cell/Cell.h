#ifndef _CELL_H
#define _CELL_H

#include "../configs.h"


class Cell {

	CELL type;

public:

	Cell(CELL type=EMPTY):type{type} {}
	virtual ~Cell()=default;

	bool operator==(CELL cell) { return type == cell; }

	char getType() const { return type; }

};

#endif