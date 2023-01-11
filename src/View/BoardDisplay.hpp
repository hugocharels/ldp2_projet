#ifndef _BOARD_DISPLAY_HPP
#define _BOARD_DISPLAY_HPP

#include "../include.hpp"
#include "AbstractDisplay.hpp"
#include "../Model/Sokoban.hpp"
#include "../Model/Cell/include.hpp"
#include "../Elements/MenuElement.hpp"


class BoardDisplay: public AbstractDisplay {

	Sokoban* model;

	inline Point modelPosToDisplayPos(Point model_pos) { return Point{CELL_SIZE+(CELL_SIZE*model_pos.y), CELL_SIZE+(CELL_SIZE*model_pos.x)}; }
	
	// DRAW
	void drawStatus();

public:

	// DRAW
	void draw() override;

	// SETTER
	void setModel(Sokoban* m) { this->model = m; }

};


#endif