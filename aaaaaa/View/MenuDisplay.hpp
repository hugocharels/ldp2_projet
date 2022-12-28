#ifndef _MENU_DISPLAY_HPP
#define _MENU_DISPLAY_HPP

#include "../include.hpp"
#include "AbstractDisplay.hpp"
#include "../Model/Sokoban.hpp"
#include "../Elements/MenuElement.hpp"


class MenuDisplay: public AbstractDisplay {

	Sokoban* model;

	int textSize=20;

	void drawButtons();
	void drawBestScore();
	void drawStepCounter();
	void drawLimitStep();
	void drawLevelSelector();
	void drawStatus();

public:

	void draw() override;

	void setModel(Sokoban* m) { this->model = m; }
	
};


#endif