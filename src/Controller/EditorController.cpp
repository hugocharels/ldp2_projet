#include "../include.hpp"
#include "EditorController.hpp"
#include "../Elements/Buttons.hpp"
#include "../images.hpp"


void EditorController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void EditorController::mouseClick(Point mouse_loc) {
	std::cout<<mouse_loc.x<<"/"<<mouse_loc.y<<std::endl;
	//séparer plus tard le mouse click entre la partie board et celle select 
	if (EDIT_ELEM_BUTTONS[0]->contains(mouse_loc)) { model->setBoxIdx(-1); }
	if (EDIT_ELEM_BUTTONS[1]->contains(mouse_loc)) { model->setBoxIdx(1); }

	if (EDIT_ELEM_BUTTONS[2]->contains(mouse_loc)) { model->setTargetIdx(-1); }
	if (EDIT_ELEM_BUTTONS[3]->contains(mouse_loc)) { model->setTargetIdx(1); }

	if (EDIT_ELEM_BUTTONS[4]->contains(mouse_loc)) { model->setTeleporterIdx(-1); }
	if (EDIT_ELEM_BUTTONS[5]->contains(mouse_loc)) { model->setTeleporterIdx(1); }

	if (EDIT_ELEM_BUTTONS[6]->contains(mouse_loc)) {std::cout<<"finish"<<std::endl;}
	//this->state = GAME_STATE::PLAY;
	//faudra save le level et retourner nouveau niveau ? check la terminaison du précédent

	//select
	if (SELECT_ELEM_BUTTONS[0]->contains(mouse_loc)) { model->placeElem(); }
	if (SELECT_ELEM_BUTTONS[1]->contains(mouse_loc)) { model->placeElem(); }
	if (SELECT_ELEM_BUTTONS[2]->contains(mouse_loc)) { model->placeElem(); }
	if (SELECT_ELEM_BUTTONS[3]->contains(mouse_loc)) { model->placeElem(); }
	if (SELECT_ELEM_BUTTONS[4]->contains(mouse_loc)) { model->placeElem(); }
	if (SELECT_ELEM_BUTTONS[5]->contains(mouse_loc)) { model->placeElem(); }
}
