#ifndef _BOARD_DISPLAY_HPP
#define _BOARD_DISPLAY_HPP

#include "AbstractDisplay.hpp"

#include "../configs.hpp"
#include "../Model/Sokoban.hpp"


class BoardDisplay: public AbstractDisplay {

	Sokoban* model;

public:

	void draw() override;

	void setModel(Sokoban* m) { this->model = m; }

};


#endif