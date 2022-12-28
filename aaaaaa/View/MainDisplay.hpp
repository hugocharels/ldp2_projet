#ifndef _MAIN_DISPLAY_HPP
#define _MAIN_DISPLAY_HPP

#include "../configs.hpp"
#include "BoardDisplay.hpp"
#include "EditorDisplay.hpp"
#include "MenuDisplay.hpp"


class MainDisplay {

	BoardDisplay  board;
	EditorDisplay editor;
	MenuDisplay   menu;

public:

	void draw(GAME_STATE state);

};


#endif