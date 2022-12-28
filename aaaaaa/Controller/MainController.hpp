#ifndef _MAIN_CONTROLLER_HPP
#define _MAIN_CONTROLLER_HPP

#include "../configs.hpp"
#include "Controller.hpp"


class MainController: public Controller {

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;

};


#endif