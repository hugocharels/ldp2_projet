#ifndef _MENU_CONTROLLER_HPP
#define _MENU_CONTROLLER_HPP

#include "../configs.hpp"
#include "AbstractController.hpp"


class MenuController: public AbstractController {

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;

};


#endif