#ifndef _EDITOR_H
#define _EDITOR_H

#include "../include.hpp"
#include "../images.hpp"
#include "Sokoban.hpp"


class Editor {

	Sokoban* model;

	int box_idx = 0;
	int target_idx = 0;
	int tp_idx = 0;
	int step_limit = 20;

	bool is_selected=false;
	CELL selected=EMPTY;

	COLOR getBoxColor() const ;
	COLOR getTargetColor() const ;
	COLOR getTeleporterColor() const ;

public:

	Editor(Sokoban* model): model{model} {}

	void save() { model->save(); }

	//CHOOSE ELEM
	int getBoxIdx() { return this->box_idx; }
	int getTargetIdx() { return this->target_idx; }
	int getTeleporterIdx() { return this->tp_idx; }
	int getStepLimit() {return step_limit;}

	void setBoxIdx(int inc) { this->box_idx = mod(this->box_idx+inc, N_TARGET); }
	void setTargetIdx(int inc){ this->target_idx = mod(this->target_idx+inc, N_TARGET); }
	void setTeleporterIdx(int inc){ this->tp_idx = mod(this->tp_idx+inc, N_TP); }
	void setStepLimit(int inc) { this->step_limit = mod(this->step_limit+inc, 100);} 

	//PLACE ELEM
	void selectElem(CELL cell);
	void placeElem(Point pos);

	bool isSelected() { return is_selected; }
	int getElemIdx();

};

#endif