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

	MainDisplay(Sokoban* model) { board.setModel(model); menu.setModel(model); }

	void draw(GAME_STATE state);

};


#endif