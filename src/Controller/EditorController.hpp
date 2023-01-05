#ifndef _EDITOR_CONTROLLER_HPP
#define _EDITOR_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractController.hpp"
#include "../Model/Editor.hpp"


class EditorController: public AbstractController {
	Editor* model;
	GAME_STATE state;
	int current_select = 0;

	void setCurrentSelect(int new_current) { current_select=new_current;}

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;
	//void clickSelect(Point mouse_loc);

	void setModel(Editor* m) { this->model = m; }
	
	GAME_STATE getNewState() const { return state; }

};


#endif