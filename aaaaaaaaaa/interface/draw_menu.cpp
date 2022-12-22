#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>
#include <vector>

#include "DisplaySokoban.h"
#include "menu_element.h"
#include "../configs.h" //pour struct point

void drawBestScore(){
	menu_element.push_back(make_shared<Text>("Best score:", Point{650,50}, textSize));
	//best_score = sokoban.getBestScore();
	//rectangle avec best score en text
}

void drawStepCounter(){
	menu_element.push_back(make_shared<Text>("Steps:", Point{650,150}, textSize));
	//count = sokoban.getPlayerPTR()->getSteps();
	//rectangle avec step dedans
}

void drawLimitStep(){
	menu_element.push_back(make_shared<Text>("Left steps:", Point{650,250}, textSize));
	//limit = sokoban.getLimit
	// rectangle avec limit-count
}