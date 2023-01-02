#ifndef _EDITOR_H
#define _EDITOR_H

#include "../include.hpp"
#include "../images.hpp"

class Editor {

	int box_idx = 0;
	int target_idx = 0;
	int tp_idx = 0;

	bool is_selected=false;
	CELL selected=EMPTY;

public:
	//CHOOSE ELEM
	int getBoxIdx() { return this->box_idx; }
	int getTargetIdx() { return this->target_idx; }
	int getTeleporterIdx() { return this->tp_idx; }

	//pê pas besoin des get, à voir
	void setBoxIdx(int inc) { this->box_idx = mod(this->box_idx+inc, N_TARGET); }
	void setTargetIdx(int inc){ this->target_idx = mod(this->target_idx+inc, N_TARGET); }
	void setTeleporterIdx(int inc){ this->tp_idx = mod(this->tp_idx+inc, N_TP); }

	//PLACE ELEM
	void selectElem(CELL cell);
	void placeElem(Point pos);

};

#endif