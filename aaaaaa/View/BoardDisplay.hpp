#ifndef _BOARD_DISPLAY_HPP
#define _BOARD_DISPLAY_HPP

#include "AbstractDisplay.hpp"

#include "../configs.hpp"
#include "../Model/Sokoban.hpp"
#include "../Model/Cell/include.hpp"


class BoardDisplay: public AbstractDisplay {

	Sokoban* model;


	inline Point modelPosToDisplayPos(Point model_pos) { return Point{cellSize+(cellSize*model_pos.y), cellSize+(cellSize*model_pos.x)}; }

	void drawCell(Point display_pos, Cell* cell);

	void drawFloor(Point display_pos);
	void drawWall(Point display_pos);
	void drawPlayer(Point display_pos);
	void drawTp(Point display_pos, COLOR color);
	void drawTarget(Point display_pos, COLOR color);
	void drawBox(Point display_pos, COLOR color);

public:

	void draw() override;

	void setModel(Sokoban* m) { this->model = m; }

};


#endif