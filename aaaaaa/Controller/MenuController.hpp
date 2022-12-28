#ifndef _MENU_CONTROLLER_HPP
#define _MENU_CONTROLLER_HPP

#include "../configs.hpp"
#include "Controller.hpp"


class MenuController: public Controller {

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;

};


#endif