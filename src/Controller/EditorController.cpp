#include "../include.hpp"
#include "EditorController.hpp"
#include "../Elements/Buttons.hpp"
#include "../images.hpp"


void EditorController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void EditorController::mouseClick(Point mouse_loc) {
	this->state = GAME_STATE::EDITOR;

	// finish
	if (EDIT_ELEM_BUTTONS[8]->contains(mouse_loc)) {
		this->model->save();
		this->state = GAME_STATE::INGAME;	
	}

	else if (EDIT_ELEM_BUTTONS[0]->contains(mouse_loc)) { 
		this->model->setBoxIdx(-1);
	} else if (EDIT_ELEM_BUTTONS[1]->contains(mouse_loc)) { 
		this->model->setBoxIdx(1);
	} else if (EDIT_ELEM_BUTTONS[2]->contains(mouse_loc)) {
		this->model->setTargetIdx(-1);
	} else if (EDIT_ELEM_BUTTONS[3]->contains(mouse_loc)) {
		this->model->setTargetIdx(1);
	} else if (EDIT_ELEM_BUTTONS[4]->contains(mouse_loc)) {
		this->model->setTeleporterIdx(-1);
	} else if (EDIT_ELEM_BUTTONS[5]->contains(mouse_loc)) {
		this->model->setTeleporterIdx(1);
	} else if (EDIT_ELEM_BUTTONS[6]->contains(mouse_loc)) {
		this->model->setStepLimit(-1);
	} else if (EDIT_ELEM_BUTTONS[7]->contains(mouse_loc)) {
		this->model->setStepLimit(1);
	}

	//select
	else if (SELECT_ELEM_BUTTONS[0]->contains(mouse_loc)) { 
		this->model->selectElem(CELL::BOX);
	} else if (SELECT_ELEM_BUTTONS[1]->contains(mouse_loc)) { 
		this->model->selectElem(CELL::PLAYER);
	} else if (SELECT_ELEM_BUTTONS[2]->contains(mouse_loc)) { 
		this->model->selectElem(CELL::TARGET);
	} else if (SELECT_ELEM_BUTTONS[3]->contains(mouse_loc)) { 
		this->model->selectElem(CELL::TP);
	} else if (SELECT_ELEM_BUTTONS[4]->contains(mouse_loc)) { 
		this->model->selectElem(CELL::WALL); 
	} else if (SELECT_ELEM_BUTTONS[5]->contains(mouse_loc)) { 
		this->model->selectElem(CELL::EMPTY);
	}
}
