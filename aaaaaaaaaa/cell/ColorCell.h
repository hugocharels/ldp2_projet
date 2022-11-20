#ifndef _COLOR_CELL_H
#define _COLOR_CELL_H

#include "Cell.h"
#include "../configs.h"


enum class COLOR { NONE = 1, RED, YELLOW, BLUE, ORANGE, GREEN, PURPLE };


class ColorCell: public virtual Cell {

	COLOR color;

public:

	ColorCell(COLOR color=COLOR::NONE): Cell('@'), color{color} {}
	
	~ColorCell()=default;

	COLOR getColor() const { return color; }

};


#endif