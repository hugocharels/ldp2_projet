#include "../include.hpp"
#include "EditorController.hpp"
#include "../Elements/Buttons.hpp"


void EditorController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void EditorController::mouseClick(Point mouse_loc) {
	//séparer plus tard le mouse click entre la partie board et celle select 
	if (EDIT_ELEM_BUTTONS[0]->contains(mouse_loc)) { model->setBoxIdx(-1); }
	if (EDIT_ELEM_BUTTONS[1]->contains(mouse_loc)) { model->setBoxIdx(1); }

	if (EDIT_ELEM_BUTTONS[3]->contains(mouse_loc)) { model->setTargetIdx(-1); }
	if (EDIT_ELEM_BUTTONS[4]->contains(mouse_loc)) { model->setTargetIdx(1); }

	if (EDIT_ELEM_BUTTONS[5]->contains(mouse_loc)) { model->setTeleporterIdx(-1); }
	if (EDIT_ELEM_BUTTONS[6]->contains(mouse_loc)) { model->setTeleporterIdx(1); }
}


/*void EditorController::clickSelect(Point mouse_loc) {
	std::cout<<mouse_loc.x<<std::endl;
	//Box
	if (MENU_BUTTONS[1]->contains(mouse_loc)) { model->setSelectIdx(model->getBoxIdx,-1, N_BOX); }
	if (MENU_BUTTONS[2]->contains(mouse_loc)) { model->setSelectIdx(model->getBoxIdx, 1, N_BOX); }

	//Target


	//TP
}*/