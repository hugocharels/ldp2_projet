#include "../include.hpp"
#include "../Model/Cell/include.hpp"
#include "../images.hpp"
#include "DrawCell.hpp"


// CHOOSE

void DrawCell::chooseImage() {
	switch(cell->getType()) {
		case EMPTY:  return this->chooseFloor();
		case WALL:   return this->chooseWall();
		case TP:     return this->chooseTp();
		case TARGET: return this->chooseTarget();
		case PLAYER: return this->choosePlayer();
		case BOX:    return this->chooseBox();
		default:     return;
	}
}

void DrawCell::chooseFloor() {
	this->image_ptr = Fl_PNG_Image(&FLOOR[0]).copy(cellSize, cellSize);
}

void DrawCell::chooseWall() {
	this->image_ptr = Fl_PNG_Image(&IM_WALL[0]).copy(cellSize, cellSize);
}

void DrawCell::choosePlayer() {
	this->image_ptr = Fl_PNG_Image(&IM_PLAYER[0]).copy(cellSize, cellSize);
}


void DrawCell::chooseTp() {
	this->drawFloor();
	switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
		case COLOR::GREEN:
			image_ptr = Fl_PNG_Image(&GREEN_TP[0]).copy(cellSize, cellSize);
			break;
		case COLOR::PINK:
			image_ptr = Fl_PNG_Image(&PINK_TP[0]).copy(cellSize, cellSize);
			break;
		case COLOR::PURPLE:
			image_ptr = Fl_PNG_Image(&PURPLE_TP[0]).copy(cellSize, cellSize);
			break;
		default:
			break;
	}
}

void DrawCell::chooseTarget() {
	this->drawFloor();
	switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
		case COLOR::NONE:
			image_ptr = Fl_PNG_Image(&NONE_TARGET[0]).copy(cellSize, cellSize);
			break;
		case COLOR::RED:
			image_ptr = Fl_PNG_Image(&RED_TARGET[0]).copy(cellSize, cellSize);
			break;
		case COLOR::ORANGE:
			image_ptr = Fl_PNG_Image(&ORANGE_TARGET[0]).copy(cellSize, cellSize);
			break;
		case COLOR::YELLOW:
			image_ptr = Fl_PNG_Image(&YELLOW_TARGET[0]).copy(cellSize, cellSize);
			break;
		case COLOR::GREEN:
			image_ptr = Fl_PNG_Image(&GREEN_TARGET[0]).copy(cellSize, cellSize);
			break;
		case COLOR::PURPLE:
			image_ptr = Fl_PNG_Image(&PURPLE_TARGET[0]).copy(cellSize, cellSize);
			break;
		case COLOR::BLUE:
			image_ptr = Fl_PNG_Image(&BLUE_TARGET[0]).copy(cellSize, cellSize);
			break;
		default:
			break;
	}
}

void DrawCell::chooseBox() {
	switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
		case COLOR::NONE:
			image_ptr = Fl_PNG_Image(&NONE_BOX[0]).copy(cellSize, cellSize);
			break;
		case COLOR::RED:
			image_ptr = Fl_PNG_Image(&RED_BOX[0]).copy(cellSize, cellSize);
			break;
		case COLOR::ORANGE:
			image_ptr = Fl_PNG_Image(&ORANGE_BOX[0]).copy(cellSize, cellSize);
			break;
		case COLOR::YELLOW:
			image_ptr = Fl_PNG_Image(&YELLOW_BOX[0]).copy(cellSize, cellSize);
			break;
		case COLOR::GREEN:
			image_ptr = Fl_PNG_Image(&GREEN_BOX[0]).copy(cellSize, cellSize);
			break;
		case COLOR::PURPLE:
			image_ptr = Fl_PNG_Image(&PURPLE_BOX[0]).copy(cellSize, cellSize);
			break;
		case COLOR::BLUE:
			image_ptr = Fl_PNG_Image(&BLUE_BOX[0]).copy(cellSize, cellSize);
			break;
		default:
			break;
	}
}

// DRAW

void DrawCell::drawFloor() {
	Cell floor = Cell{EMPTY};
	DrawCell(this->display_pos, &floor).draw();
}
