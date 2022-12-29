#include "../include.hpp"
#include "MenuController.hpp"
#include "../Elements/Buttons.hpp"


void MenuController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void MenuController::mouseClick(Point mouse_loc) {

	// RESET LEVEL
	if (MENU_BUTTONS[0]->contains(mouse_loc)) { model->resetBestScore(); }
	
	// PREVIOUS LEVEL
	if (MENU_BUTTONS[1]->contains(mouse_loc)) { model->setSelectIdx(-1); }
	
	// NEXT LEVEL
	if (MENU_BUTTONS[2]->contains(mouse_loc)) { model->setSelectIdx(1); }
	
	// LOAD LEVEL
	if (MENU_BUTTONS[3]->contains(mouse_loc)) { this->model->restart(this->model->getSelectIdx()); }
	
	// CREATE LEVEL
	if (MENU_BUTTONS[4]->contains(mouse_loc)) { std::cout<<"Create"<<std::endl; }
}
