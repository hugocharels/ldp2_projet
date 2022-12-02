#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>

#include "DisplaySokoban.h"
#include "../cell/include.h"
#include "../configs.h"
#include "../images.h"


void inline DisplaySokoban::drawAFloor(Point display_pos) {
	Fl_Image* image_ptr = Fl_PNG_Image(FLOOR).copy(cellSize, cellSize);
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}

void inline DisplaySokoban::drawAWall(Point display_pos) {
	Fl_Image* image_ptr = Fl_PNG_Image(IM_WALL).copy(cellSize, cellSize);
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}

void inline DisplaySokoban::drawAPlayer(Point display_pos) {
	Fl_Image* image_ptr = Fl_PNG_Image(IM_PLAYER).copy(cellSize, cellSize);
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}


void inline DisplaySokoban::drawATp(Point display_pos, COLOR color) {
	this->drawAFloor(display_pos);
	Fl_Image* image_ptr;
	switch(color) {
		case COLOR::GREEN:
			image_ptr = Fl_PNG_Image(GREEN_TP).copy(cellSize, cellSize);
			break;
		case COLOR::PINK:
			image_ptr = Fl_PNG_Image(PINK_TP).copy(cellSize, cellSize);
			break;
		case COLOR::PURPLE:
			image_ptr = Fl_PNG_Image(PURPLE_TP).copy(cellSize, cellSize);
			break;
		default:
			break;
	}
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}


void inline DisplaySokoban::drawATarget(Point display_pos, COLOR color) {
	this->drawAFloor(display_pos);
	Fl_Image* image_ptr;
	switch(color) {
		case COLOR::NONE:
			image_ptr = Fl_PNG_Image(NONE_TARGET).copy(cellSize, cellSize);
			break;
		case COLOR::RED:
			image_ptr = Fl_PNG_Image(RED_TARGET).copy(cellSize, cellSize);
			break;
		case COLOR::ORANGE:
			image_ptr = Fl_PNG_Image(ORANGE_TARGET).copy(cellSize, cellSize);
			break;
		case COLOR::YELLOW:
			image_ptr = Fl_PNG_Image(YELLOW_TARGET).copy(cellSize, cellSize);
			break;
		case COLOR::GREEN:
			image_ptr = Fl_PNG_Image(GREEN_TARGET).copy(cellSize, cellSize);
			break;
		case COLOR::PURPLE:
			image_ptr = Fl_PNG_Image(PURPLE_TARGET).copy(cellSize, cellSize);
			break;
		case COLOR::BLUE:
			image_ptr = Fl_PNG_Image(BLUE_TARGET).copy(cellSize, cellSize);
			break;
		default:
			break;
	}
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}


void inline DisplaySokoban::drawABox(Point display_pos, COLOR color) {
	Fl_Image* image_ptr;
	switch(color) {
		case COLOR::NONE:
			image_ptr = Fl_PNG_Image(NONE_BOX).copy(cellSize, cellSize);
			break;
		case COLOR::RED:
			image_ptr = Fl_PNG_Image(RED_BOX).copy(cellSize, cellSize);
			break;
		case COLOR::ORANGE:
			image_ptr = Fl_PNG_Image(ORANGE_BOX).copy(cellSize, cellSize);
			break;
		case COLOR::YELLOW:
			image_ptr = Fl_PNG_Image(YELLOW_BOX).copy(cellSize, cellSize);
			break;
		case COLOR::GREEN:
			image_ptr = Fl_PNG_Image(GREEN_BOX).copy(cellSize, cellSize);
			break;
		case COLOR::PURPLE:
			image_ptr = Fl_PNG_Image(PURPLE_BOX).copy(cellSize, cellSize);
			break;
		case COLOR::BLUE:
			image_ptr = Fl_PNG_Image(BLUE_BOX).copy(cellSize, cellSize);
			break;
		default:
			break;
	}
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}


void inline DisplaySokoban::drawACell(Point display_pos, Cell* cell){
	switch(cell->getType()) {
		case EMPTY:
			this->drawAFloor(display_pos);
			break;
		case WALL:
			this->drawAWall(display_pos);
			break;
		case TP:
			this->drawATp(display_pos, dynamic_cast<ColorCell*>(cell)->getColor());
			break;
		case TARGET:
			this->drawATarget(display_pos, dynamic_cast<ColorCell*>(cell)->getColor());
			break;
		case PLAYER:
			this->drawAPlayer(display_pos);
			break;
		case BOX:
			this->drawABox(display_pos, dynamic_cast<ColorCell*>(cell)->getColor());
			break;
		default:
			break;
	}
}


void DisplaySokoban::draw(){
	//draw la map 
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
