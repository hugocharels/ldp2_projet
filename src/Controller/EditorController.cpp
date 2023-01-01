#include "../include.hpp"
#include "EditorController.hpp"
#include "../Elements/Buttons.hpp"


void EditorController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void EditorController::mouseClick(Point mouse_loc) {
	if (EDIT_ELEM_BUTTONS[0]->contains(mouse_loc)) { model->setIdx(model->getBoxIdx(),-1, N_BOX); }
	if (EDIT_ELEM_BUTTONS[1]->contains(mouse_loc)) { model->setIdx(model->getBoxIdx(), 1, N_BOX); }
}


/*void EditorController::clickSelect(Point mouse_loc) {
	std::cout<<mouse_loc.x<<std::endl;
	//Box
	if (MENU_BUTTONS[1]->contains(mouse_loc)) { model->setSelectIdx(model->getBoxIdx,-1, N_BOX); }
	if (MENU_BUTTONS[2]->contains(mouse_loc)) { model->setSelectIdx(model->getBoxIdx, 1, N_BOX); }

	//Target


	//TP
}*/