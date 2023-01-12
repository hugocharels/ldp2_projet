#ifndef _MAIN_CONTROLLER_HPP
#define _MAIN_CONTROLLER_HPP

#include "../include.hpp"
#include "GameBoardController.hpp"
#include "EditorBoardController.hpp"
#include "EditorController.hpp"
#include "MenuController.hpp"


class MainController {

	GameBoardController  game_board;
	EditorBoardController  editor_board;
	EditorController editor;
	MenuController   menu;

public:

	MainController(Sokoban* model, Editor* edit_model) { game_board.setModel(model); menu.setModel(model); editor.setModel(edit_model); editor_board.setModel(edit_model); }

	// EVENTS
	void keyPressed(int key_code, GAME_STATE &state);
	void mouseClick(Point mous_loc, GAME_STATE &state);

};


#endif