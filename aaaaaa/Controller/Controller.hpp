#ifndef _CONTROLLER_HPP
#define _CONTROLLER_HPP

#include "../configs.hpp"


class Controller {

public:

	virtual void keyPressed(int key_code)=0;
	virtual void mouseClick(Point mous_loc)=0;

};


#endif