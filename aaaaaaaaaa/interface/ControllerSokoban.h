#ifndef _CONTROLLER_SOKOBAN_H
#define _CONTROLLER_SOKOBAN_H

#include <FL/Fl.H>

#include "../game/Sokoban.h"
#include "../configs.h"


class ControllerSokoban {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;

public:

	ControllerSokoban(Fl_Window* fltkWindow, Sokoban* sokoban) :fltkWindow{fltkWindow},sokoban{sokoban} {}

	void keyPressed(int key_code) {
		MOVE move = INVALID;
		switch(key_code) {
			case 'z':
				move = UP;
				break;
			case 's':
				move = DOWN;
				break;
			case 'q':
				move = LEFT;
				break;
			case 'd':
				move = RIGHT;
				break;
		}
		this->sokoban->inputPlayer(move);
	}

	void mouseClick(Point mouse_loc) {
		this->sokoban->restart();
		std::cout << mouse_loc.x << " / " << mouse_loc.y << std::endl;
	}
};


#endif