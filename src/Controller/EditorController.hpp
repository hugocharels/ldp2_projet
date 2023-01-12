#ifndef _EDITOR_CONTROLLER_HPP
#define _EDITOR_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractController.hpp"
#include "../Model/Editor.hpp"


class EditorController: public AbstractController {

	Editor* model;
	GAME_STATE state;

public:

	// EVENTS
	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;

	// GETTER
	GAME_STATE getNewState() const { return state; }
	
	// SETTER
	void setModel(Editor* m) { this->model = m; }

};

#endif