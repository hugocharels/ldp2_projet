#ifndef _DRAW_CELL_HPP
#define _DRAW_CELL_HPP

#include "../include.hpp"
#include "../Model/Cell/include.hpp"


class DrawCell {

	Point display_pos;
	Cell* cell;
	Fl_Image* image_ptr;

	// CHOOSE IMAGE
	void chooseImage();
	void chooseFloor();
	void chooseWall();
	void choosePlayer();
	void chooseTp();
	void chooseTarget();
	void chooseBox();

	// DRAW
	void draw() { this->image_ptr->draw(display_pos.x, display_pos.y); }
	void drawFloor();

public:

	DrawCell(Point display_pos, Cell* cell=nullptr): display_pos{display_pos}, cell{cell} { this->chooseImage(); this->draw(); }
	DrawCell(Point display_pos, const std::string image): display_pos{display_pos}, image_ptr{Fl_PNG_Image(&image[0]).copy(cellSize, cellSize)} { this->draw(); }

	~DrawCell() { delete this->image_ptr; }

};

#endif