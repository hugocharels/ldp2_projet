#ifndef _GAME_BOARD_CONTROLLER_HPP
#define _GAME_BOARD_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractBoardController.hpp"


class GameBoardController: public AbstractBoardController {

	GAME_STATE state;

public:

	virtual void keyPressed(int key_code) override;
	virtual void mouseClick(Point mouse_loc) override;

	GAME_STATE getNewState() const { return state; }

};

#endif