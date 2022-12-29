#ifndef _BOARD_CONTROLLER_HPP
#define _BOARD_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractController.hpp"
#include "../Model/Sokoban.hpp"


class BoardController: public AbstractController {
	
	Sokoban* model;

	inline Point displayPosToBoardPos(Point display_pos) { return Point{(display_pos.y / cellSize) - 1, (display_pos.x / cellSize) - 1}; }
	
public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mouse_loc) override;

	void setModel(Sokoban* m) { this->model = m; }

};


#endif