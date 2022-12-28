#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>

#include "DisplaySokoban.h"

const char* WELCOME = "dessin_temp/soko_mainpage.png";


void DisplaySokoban::drawMap(){
	auto* other_cells = sokoban->getToutDeg(); //matrix map pointer
	Player* player = sokoban->getPlayerPTR(); 
	auto* boxes = sokoban->getTouBoxDeg(); //pointer vector box

	for (int i=0; i<other_cells->getRows(); i++){
		for (int j=0; j<other_cells->getCols(); j++){
			drawACell(modelPosToDisplayPos(Point{i,j}), other_cells->at(i,j).get());
		}
	}
	// player
	drawACell(modelPosToDisplayPos(player->getPos()), player);
	// box
	for (auto& box: *boxes){ drawACell(modelPosToDisplayPos(box.getPos()), &box);}
}

void DisplaySokoban::drawMenu(){
	drawBestScore();
	drawStepCounter();
	drawLimitStep();
	drawLevelSelector();
	drawStatus();

	for(auto &elem : menu_elem){
		elem->print();
	}
}

void DisplaySokoban::drawWelcome() {
	Fl_Image* image_ptr = Fl_PNG_Image(WELCOME).copy(windowWidth, windowHeight);
	image_ptr->draw(0, 0);
	delete image_ptr;
}


void DisplaySokoban::draw(){
	if (aaaa++ <= refreshPerSecond*5) {
		drawWelcome();
	} else {
		drawMap();
		drawMenu();
		this->menu_elem.clear();
	}
}

