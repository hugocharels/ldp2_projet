#ifndef _MENU_DISPLAY_HPP
#define _MENU_DISPLAY_HPP

#include "../include.hpp"
#include "AbstractDisplay.hpp"
#include "../Model/Sokoban.hpp"
#include "../Elements/MenuElement.hpp"


class MenuDisplay: public AbstractDisplay {

	Sokoban* model;

	int textSize=20;

	// DRAW
	void drawButtons();
	void drawBestScore();
	void drawStepCounter();
	void drawLimitStep();
	void drawLevelSelector();

public:

	// DRAW
	void draw() override;
	void drawWelcome();

	// SETTER
	void setModel(Sokoban* m) { this->model = m; }
	
};


#endif