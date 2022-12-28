#ifndef _MENU_DISPLAY_HPP
#define _MENU_DISPLAY_HPP

#include "../configs.hpp"
#include "AbstractDisplay.hpp"


class MenuDisplay: public AbstractDisplay {

public:

	void draw() override;

};


#endif