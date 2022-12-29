#ifndef _MENU_CONTROLLER_HPP
#define _MENU_CONTROLLER_HPP

#include "../include.hpp"
#include "AbstractController.hpp"
#include "../Model/Sokoban.hpp"


class MenuController: public AbstractController {

	Sokoban* model;
	GAME_STATE state;
	
public:

	void keyPressed(int key_code) override;
	void mouseClick(Point mous_loc) override;

	void setModel(Sokoban* m) { this->model = m; }
	
	GAME_STATE getNewState() const { return state; }

};


#endif