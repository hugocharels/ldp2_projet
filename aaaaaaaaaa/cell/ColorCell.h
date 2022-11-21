#ifndef _COLOR_CELL_H
#define _COLOR_CELL_H

#include "Cell.h"
#include "../configs.h"


enum class COLOR { NONE = 1, RED, YELLOW, BLUE, ORANGE, GREEN, PURPLE };


class ColorCell: public virtual Cell {

	COLOR color;

public:

	ColorCell(CELL cell, COLOR color=COLOR::NONE): Cell(cell), color{color} {}
	
	~ColorCell()=default;

	virtual COLOR getColor() const { return color; }
	virtual void setColor(COLOR new_color) { this->color = new_color; }

};


#endif