#ifndef _EDITOR_CONTROLLER_HPP
#define _EDITOR_CONTROLLER_HPP

#include "../configs.hpp"
#include "Controller.hpp"


class EditorController: public Controller {

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;

};


#endif