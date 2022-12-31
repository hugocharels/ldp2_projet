#ifndef _EDITOR_H
#define _EDITOR_H

#include "../include.hpp"

class Editor {
	int box_idx = 0;
	int target_idx = 0;
	int tp_idx = 0;

public:
	int getBoxIdx() {return box_idx;}
	int getTargetIdx() {return target_idx;}
	int getTPIdx() {return tp_idx;}
	void setIdx(int select_idx) {select_idx = mod(select_idx+inc, levels.getSize()) ;}
}

#endif