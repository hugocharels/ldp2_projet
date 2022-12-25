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
	menu_elem.push_back(std::make_shared<Text>("Best score:", Point{650, 60}, textSize));
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{650,90}, 125, 35, std::to_string(sokoban->getBestScore())));
}

void DisplaySokoban::drawStepCounter(){
	menu_elem.push_back(std::make_shared<Text>("Steps:", Point{650,160}, textSize));
	int count = sokoban->getPlayerPTR()->getSteps();
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{650,190}, 125, 35, std::to_string(count)));
}

void DisplaySokoban::drawLimitStep(){
	menu_elem.push_back(std::make_shared<Text>("Left steps:", Point{650,260}, textSize));
	int step_remaining = sokoban->getStepLimit() - sokoban->getPlayerPTR()->getSteps();
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{650,290}, 125, 35, std::to_string(step_remaining)));
}

void DisplaySokoban::drawLevelSelector(){
	menu_elem.push_back(std::make_shared<Text>("Select level:", Point{650,370}, textSize));
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{650,400}, 110, 35, "Level 1"));
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{620,440}, 60, 30, "Create"));
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{690,440}, 60, 30, "Load"));
}

void DisplaySokoban::drawStatus(){
	menu_elem.push_back(std::make_shared<TextRectangle>(Point{300,550}, 500, 35, sokoban->getStatus()));
}