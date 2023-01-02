#ifndef _GAME_BOARD_CONTROLLER_HPP
#define _GAME_BOARD_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractBoardController.hpp"
#include "../Model/Sokoban.hpp"


class GameBoardController: public AbstractBoardController {

	Sokoban* model;

	GAME_STATE state;

public:

	virtual void keyPressed(int key_code) override;
	virtual void mouseClick(Point mouse_loc) override;

	void setModel(Sokoban* m) { this->model = m; }

	GAME_STATE getNewState() const { return state; }

};

#endif