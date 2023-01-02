#ifndef _EDITOR_BOARD_CONTROLLER_HPP
#define _EDITOR_BOARD_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractBoardController.hpp"


class EditorBoardController: public AbstractBoardController {

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mouse_loc) override;

};

#endif