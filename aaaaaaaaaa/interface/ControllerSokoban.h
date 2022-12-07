#ifndef _CONTROLLER_SOKOBAN_H
#define _CONTROLLER_SOKOBAN_H

#include <FL/Fl.H>

#include "../game/Sokoban.h"
#include "../configs.h"


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
				this->sokoban->restart();
		}
		this->sokoban->inputPlayer(move);
	}

	void mouseClick(Point mouse_loc) {
		this->sokoban->movePlayerTo(this->displayPosToBoardPos(mouse_loc));
	}
};


#endif