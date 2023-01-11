#ifndef _BOARD_DISPLAY_HPP
#define _BOARD_DISPLAY_HPP

#include "../include.hpp"
#include "AbstractDisplay.hpp"
#include "../Model/Sokoban.hpp"
#include "../Model/Cell/include.hpp"
#include "../Elements/MenuElement.hpp"


class BoardDisplay: public AbstractDisplay {

	Sokoban* model;

	inline Point modelPosToDisplayPos(Point model_pos) { return Point{cellSize+(cellSize*model_pos.y), cellSize+(cellSize*model_pos.x)}; }
	
	// DRAW
	void drawStatus();

public:

	// DRAW
	void draw() override;

	// SETTER
	void setModel(Sokoban* m) { this->model = m; }

};


#endif