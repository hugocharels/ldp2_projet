#ifndef _COLOR_CELL_H
#define _COLOR_CELL_H

#include "Cell.h"
#include "../configs.h"


enum class COLOR { NONE = 1, RED, YELLOW, BLUE, ORANGE, GREEN, PURPLE };


COLOR charToColor(char x) {
	if (x == '2') { return COLOR::RED; }
	else if (x == '3') { return COLOR::YELLOW; }
	else if (x == '4') { return COLOR::BLUE; }
	else if (x == '5') { return COLOR::ORANGE; }
	else if (x == '5') { return COLOR::GREEN; }
	else if (x == '5') { return COLOR::PURPLE; }
	return COLOR::NONE;
}


class ColorCell: public virtual Cell {

	COLOR color;

public:

	ColorCell(CELL cell, COLOR color=COLOR::NONE): Cell(cell), color{color} {}
	
	~ColorCell()=default;

	virtual COLOR getColor() const { return color; }
	virtual void setColor(COLOR new_color) { this->color = new_color; }

};


#endif