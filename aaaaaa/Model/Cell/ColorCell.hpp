#ifndef _COLOR_CELL_HPP
#define _COLOR_CELL_HPP

#include "Cell.hpp"
#include "../../configs.hpp"


class ColorCell: public virtual Cell {

	COLOR color;

public:


	ColorCell(CELL cell, COLOR color=COLOR::NONE): Cell(cell), color{color} {}
	
	~ColorCell()=default;

	virtual COLOR getColor() const { return color; }
	virtual void setColor(COLOR new_color) { this->color = new_color; }

};


#endif