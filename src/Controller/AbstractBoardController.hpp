#ifndef _ABSTRACT_BOARD_CONTROLLER_HPP
#define _ABSTRACT_BOARD_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractController.hpp"


class AbstractBoardController: public AbstractController {

protected:

	inline Point displayPosToBoardPos(Point display_pos) { return Point{(display_pos.y / CELL_SIZE) - 1, (display_pos.x / CELL_SIZE) - 1}; }
	
public:

	// EVENTS
	virtual void keyPressed(int key_code)=0;
	virtual void mouseClick(Point mouse_loc)=0;

};


#endif