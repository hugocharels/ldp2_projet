#ifndef _ABSTRACT_CONTROLLER_HPP
#define _ABSTRACT_CONTROLLER_HPP

#include "../configs.hpp"


class AbstractController {

public:

	virtual void keyPressed(int key_code)=0;
	virtual void mouseClick(Point mous_loc)=0;

};


#endif