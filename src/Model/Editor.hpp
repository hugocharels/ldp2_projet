#ifndef _EDITOR_H
#define _EDITOR_H

#include "../include.hpp"
#include "../images.hpp"

class Editor {
	std::array<std::string, N_BOX> box_list{NONE_BOX, RED_BOX, ORANGE_BOX, YELLOW_BOX, GREEN_BOX, BLUE_BOX, PURPLE_BOX };
	std::array<std::string, N_TARGET> target_list{NONE_TARGET, RED_TARGET, ORANGE_TARGET, YELLOW_TARGET, GREEN_TARGET, BLUE_TARGET, PURPLE_TARGET };
	std::array<std::string, N_TP> tp_list{GREEN_TP, PINK_TP, PURPLE_TP};
	int* box_idx = 0;
	int* target_idx = 0;
	int* tp_idx = 0;

public:
	std::string getBoxImage() {return this->box_list[*box_idx];};
	int* getBoxIdx() {return box_idx;}
	int* getTargetIdx() {return target_idx;}
	int* getTPIdx() {return tp_idx;}
	void setIdx(int *select_idx, int inc,int size) {
		std::cout<<"before"<<select_idx<<this->box_idx<<std::endl; 
		*select_idx = mod(*select_idx+inc, size); 
		std::cout<<"after"<<select_idx<<this->box_idx<<std::endl;}
};

//std::cout<<this->box_list[this->box_idx] <<std::endl;

#endif