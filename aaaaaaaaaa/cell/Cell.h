#ifndef _CELL_H
#define _CELL_H

#include "../configs.h"


class Cell {

	char type;

public:

	Cell(char type='0'):type{type} {}
	~Cell()=default;

	char getType() const { return type; }

};

#endif