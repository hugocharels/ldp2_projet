#ifndef _MENU_DISPLAY_HPP
#define _MENU_DISPLAY_HPP

#include "../include.hpp"
#include "AbstractDisplay.hpp"


class MenuDisplay: public AbstractDisplay {

	//std::vector<std::shared_ptr<Printable>> menu_elem;
	int textSize=20;

public:

	void draw() override;

};


#endif