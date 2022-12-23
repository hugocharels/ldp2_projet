#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>
#include <vector>
#include <string>

#include "DisplaySokoban.h"
//#include "menu_element.h"
#include "../configs.h" //pour struct point

void DisplaySokoban::drawBestScore(){
	menu_elem.push_back(std::make_shared<Text>("Best score:", Point{650,50}, textSize));
	//best_score = sokoban.getBestScore();
	//rectangle avec best score en text
}

void DisplaySokoban::drawStepCounter(){
	menu_elem.push_back(std::make_shared<Text>("Steps:", Point{650,150}, textSize));
	int count = sokoban->getPlayerPTR()->getSteps();
	//rectangle avec step dedans
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{650,175}, 150, 30, std::to_string(count)));
	//burk
}

void DisplaySokoban::drawLimitStep(){
	menu_elem.push_back(std::make_shared<Text>("Left steps:", Point{650,250}, textSize));
	//limit = sokoban.getLimit
	// rectangle avec limit-count
}