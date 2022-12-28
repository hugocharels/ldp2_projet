#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>

#include "../configs.hpp"
#include "BoardDisplay.hpp"
#include "../Model/Cell/include.hpp"
#include "../images.hpp"


void BoardDisplay::draw() {
	auto* other_cells = model->getToutDeg(); //matrix map pointer
	Player* player = model->getPlayerPTR(); 
	auto* boxes = model->getTouBoxDeg(); //pointer vector box

	for (int i=0; i<other_cells->getRows(); i++){
		for (int j=0; j<other_cells->getCols(); j++){
			drawCell(modelPosToDisplayPos(Point{i,j}), other_cells->at(i,j).get());
		}
	}
	// player
	drawCell(modelPosToDisplayPos(player->getPos()), player);
	// box
	for (auto& box: *boxes){ drawCell(modelPosToDisplayPos(box.getPos()), &box);}

}


void BoardDisplay::drawCell(Point display_pos, Cell* cell){
	switch(cell->getType()) {
		case EMPTY:
			this->drawFloor(display_pos);
			break;
		case WALL:
			this->drawWall(display_pos);
			break;
		case TP:
			this->drawTp(display_pos, dynamic_cast<ColorCell*>(cell)->getColor());
			break;
		case TARGET:
			this->drawTarget(display_pos, dynamic_cast<ColorCell*>(cell)->getColor());
			break;
		case PLAYER:
			this->drawPlayer(display_pos);
			break;
		case BOX:
			this->drawBox(display_pos, dynamic_cast<ColorCell*>(cell)->getColor());
			break;
		default:
			break;
	}
}


void BoardDisplay::drawFloor(Point display_pos) {
	Fl_Image* image_ptr = Fl_PNG_Image(FLOOR).copy(cellSize, cellSize);
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}

void BoardDisplay::drawWall(Point display_pos) {
	Fl_Image* image_ptr = Fl_PNG_Image(IM_WALL).copy(cellSize, cellSize);
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}

void BoardDisplay::drawPlayer(Point display_pos) {
	Fl_Image* image_ptr = Fl_PNG_Image(IM_PLAYER).copy(cellSize, cellSize);
	image_ptr->draw(display_pos.x, display_pos.y);
	delete image_ptr;
}


void BoardDisplay::drawTp(Point display_pos, COLOR color) {
	this->drawFloor(display_pos);
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


void BoardDisplay::drawTarget(Point display_pos, COLOR color) {
	this->drawFloor(display_pos);
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


void BoardDisplay::drawBox(Point display_pos, COLOR color) {
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

