#ifndef _MAIN_DISPLAY_HPP
#define _MAIN_DISPLAY_HPP

#include "../include.hpp"
#include "BoardDisplay.hpp"
#include "EditorDisplay.hpp"
#include "MenuDisplay.hpp"
#include "../Model/Sokoban.hpp"


class MainDisplay {

	BoardDisplay  board;
	EditorDisplay editor;
	MenuDisplay   menu;

public:

	MainDisplay(Sokoban* model, Editor* edit_model ) { board.setModel(model); menu.setModel(model); editor.setModel(edit_model);}

	// DRAW
	void draw(GAME_STATE state);

};


#endif