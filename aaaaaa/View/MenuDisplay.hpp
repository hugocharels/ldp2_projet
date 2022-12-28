#ifndef _MENU_DISPLAY_HPP
#define _MENU_DISPLAY_HPP

#include "../include.hpp"
#include "AbstractDisplay.hpp"
#include "../Elements/MenuElement.hpp"


class MenuDisplay: public AbstractDisplay {

	std::vector<std::shared_ptr<Printable>> elements;
	int textSize=20;

	void drawButtons();

public:

	void draw() override;

};


#endif