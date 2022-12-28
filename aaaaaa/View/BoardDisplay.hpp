#ifndef _BOARD_DISPLAY_HPP
#define _BOARD_DISPLAY_HPP

#include "Display.hpp"

#include "../Model/Sokoban.hpp"


class BoardDisplay: public Display {

	Sokoban* model;

public:

	void draw() override;

	void setModel(Sokoban* m) { this->model = m; }

};


#endif