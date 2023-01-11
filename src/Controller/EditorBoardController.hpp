#ifndef _EDITOR_BOARD_CONTROLLER_HPP
#define _EDITOR_BOARD_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractBoardController.hpp"
#include "../Model/Editor.hpp"


class EditorBoardController: public AbstractBoardController {

	Editor* model;

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mouse_loc) override;

	void setModel(Editor* m) { this->model = m; }

};

#endif