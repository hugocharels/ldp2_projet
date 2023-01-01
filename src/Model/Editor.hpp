#ifndef _EDITOR_H
#define _EDITOR_H

#include "../include.hpp"
#include "../images.hpp"

class Editor {
	std::array<std::string, N_BOX> box_list{NONE_BOX, RED_BOX, ORANGE_BOX, YELLOW_BOX, GREEN_BOX, BLUE_BOX, PURPLE_BOX };
	std::array<std::string, N_TARGET> target_list{NONE_TARGET, RED_TARGET, ORANGE_TARGET, YELLOW_TARGET, GREEN_TARGET, BLUE_TARGET, PURPLE_TARGET };
	std::array<std::string, N_TP> tp_list{GREEN_TP, PINK_TP, PURPLE_TP};
	int box_idx = 0;
	int target_idx = 0;
	int tp_idx = 0;

public:
	std::string getBoxImage() {return this->box_list[this->box_idx];};
	int getBoxIdx() {return box_idx;}
	int getTargetIdx() {return target_idx;}
	int getTPIdx() {return tp_idx;}
	void setIdx(int inc) { this->box_idx = mod(this->box_idx+inc, N_TARGET); }
	void setTargetIdx(int inc){ this->target_idx = mod(this->target_idx+inc, N_TARGET); }
};

//std::cout<<this->box_list[this->box_idx] <<std::endl;
//box_list[*box_idx];
#endif