#ifndef _MAIN_CONTROLLER_HPP
#define _MAIN_CONTROLLER_HPP

#include "../configs.hpp"
#include "BoardController.hpp"
#include "EditorController.hpp"
#include "MenuController.hpp"


class MainController {

	BoardController  board;
	EditorController editor;
	MenuController   menu;

public:

	void keyPressed(int key_code, GAME_STATE state);
	void mouseClick(Point mous_loc, GAME_STATE state);

};


#endif