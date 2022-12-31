#include "../include.hpp"
#include "EditorController.hpp"

void EditorController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void EditorController::mouseClick(Point mouse_loc) {
	std::cout << mouse_loc.x << "/" << mouse_loc.y << std::endl; 
}


void EditorController::clickSelect(Point mouse_loc) {
	std::cout<<mouse_loc.x<<std::endl;
	//Box
	/*if (MENU_BUTTONS[1]->contains(mouse_loc)) { model->setSelectIdx(-1); }
	if (MENU_BUTTONS[2]->contains(mouse_loc)) { model->setSelectIdx(1); }*/

	//Target


	//TP
}