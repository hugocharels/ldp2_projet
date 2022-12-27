#ifndef _CONTROLLER_SOKOBAN_H
#define _CONTROLLER_SOKOBAN_H

#include <FL/Fl.H>

#include <iostream>

#include "../game/Sokoban.h"
#include "../configs.h"
#include "menu_element.h"
#include "../configs_buttons.h"


class ControllerSokoban {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;

	Point displayPosToBoardPos(Point display_pos) { return Point{(display_pos.y / cellSize) - 1, (display_pos.x / cellSize) - 1}; }

public:

	ControllerSokoban(Fl_Window* fltkWindow, Sokoban* sokoban) :fltkWindow{fltkWindow},sokoban{sokoban} {}

	void keyPressed(int key_code) {
		MOVE move = INVALID;
		switch(key_code) {
			case 65362:
			case 'z':
				move = UP;
				break;
			case 65364:
			case 's':
				move = DOWN;
				break;
			case 65361:
			case 'q':
				move = LEFT;
				break;
			case 65363:
			case 'd':
				move = RIGHT;
				break;
			case ' ':
				this->sokoban->restart(this->sokoban->getCurrentIdx());
		}
		this->sokoban->inputPlayer(move);
	}

	void mouseClick(Point mouse_loc) {

		
		this->sokoban->inputPlayer(INVALID);	
		Point pos = this->displayPosToBoardPos(mouse_loc);
		std::vector<MOVE> moves;
		this->sokoban->canMovePlayerTo(moves, pos);
		if (not moves.empty()) { this->sokoban->movePlayer(moves); }
		this->sokoban->inputPlayer(INVALID);

		/*
		if contains ce bouton mouselock (les points)
			take action !!!
		puis pour tous les boutons lo 
		*/
		if (MENU_BUTTONS[0]->contains(mouse_loc)) {
			std::cout<<"reset"<<std::endl;
			sokoban->resetBestScore();
		}
		
		if (MENU_BUTTONS[1]->contains(mouse_loc)) {
			std::cout<<"<<"<<std::endl;
			sokoban->setSelectIdx(-1);
		}

		if (MENU_BUTTONS[2]->contains(mouse_loc)) {
			std::cout<<">>"<<std::endl;
			sokoban->setSelectIdx(1);
		}

		if (MENU_BUTTONS[3]->contains(mouse_loc)) {
			std::cout<<"Load"<<std::endl;
			this->sokoban->restart(this->sokoban->getSelectIdx());
		}

		if (MENU_BUTTONS[4]->contains(mouse_loc)) {
			std::cout<<"Create"<<std::endl;
		}
	}
};


#endif