#ifndef _BOARD_CONTROLLER_HPP
#define _BOARD_CONTROLLER_HPP

#include "../configs.hpp"
#include "AbstractController.hpp"


class BoardController: public AbstractController {
	
	Sokoban* model;

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;

	void setModel(Sokoban* m) { this->model = m; }

};


#endif