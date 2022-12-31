#ifndef _EDITOR_CONTROLLER_HPP
#define _EDITOR_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractController.hpp"


class EditorController: public AbstractController {

public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;
	void clickSelect(Point mouse_loc);

};


#endif