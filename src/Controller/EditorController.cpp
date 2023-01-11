#include "../include.hpp"
#include "EditorController.hpp"
#include "../Elements/Buttons.hpp"
#include "../images.hpp"


void EditorController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void EditorController::mouseClick(Point mouse_loc) {
	this->state = GAME_STATE::EDITOR;

	if (EDIT_ELEM_BUTTONS[0]->contains(mouse_loc)) { model->setBoxIdx(-1); }
	if (EDIT_ELEM_BUTTONS[1]->contains(mouse_loc)) { model->setBoxIdx(1); }

	if (EDIT_ELEM_BUTTONS[2]->contains(mouse_loc)) { model->setTargetIdx(-1); }
	if (EDIT_ELEM_BUTTONS[3]->contains(mouse_loc)) { model->setTargetIdx(1); }

	if (EDIT_ELEM_BUTTONS[4]->contains(mouse_loc)) { model->setTeleporterIdx(-1); }
	if (EDIT_ELEM_BUTTONS[5]->contains(mouse_loc)) { model->setTeleporterIdx(1); }

	if (EDIT_ELEM_BUTTONS[6]->contains(mouse_loc)) { model->setStepLimit(-1); }
	if (EDIT_ELEM_BUTTONS[7]->contains(mouse_loc)) { model->setStepLimit(1); }

	// finish
	if (EDIT_ELEM_BUTTONS[8]->contains(mouse_loc)) {
		model->save();
		this->state = GAME_STATE::PLAY;	
	}

	//select
	if (SELECT_ELEM_BUTTONS[0]->contains(mouse_loc)) { 
		SELECT_ELEM_BUTTONS[0]->setFillColor(FL_RED);
		SELECT_ELEM_BUTTONS[0]->setHeight(15);
		model->selectElem(CELL::BOX);
	}
	if (SELECT_ELEM_BUTTONS[1]->contains(mouse_loc)) { 
		SELECT_ELEM_BUTTONS[1]->setFillColor(FL_RED);
		model->selectElem(CELL::PLAYER);
	}
	if (SELECT_ELEM_BUTTONS[2]->contains(mouse_loc)) { 
		SELECT_ELEM_BUTTONS[2]->setFillColor(FL_RED);
		model->selectElem(CELL::TARGET);
	}
	if (SELECT_ELEM_BUTTONS[3]->contains(mouse_loc)) { 
		SELECT_ELEM_BUTTONS[3]->setFillColor(FL_RED);
		model->selectElem(CELL::TP);
	}
	if (SELECT_ELEM_BUTTONS[4]->contains(mouse_loc)) { 
		SELECT_ELEM_BUTTONS[4]->setFillColor(FL_RED);
		model->selectElem(CELL::WALL); 
	}
	if (SELECT_ELEM_BUTTONS[5]->contains(mouse_loc)) { 
		SELECT_ELEM_BUTTONS[5]->setFillColor(FL_RED);
		model->selectElem(CELL::EMPTY);
	}
}
