#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>

#include "DisplaySokoban.h"
#include "../cell/include.h"
#include "../configs.h"
#include "../images.h"


void DisplaySokoban::drawACell(Point display_pos, Cell* cell){
	Fl_Image* ptr_image;
	switch(cell->getType()) {
		case EMPTY:
			ptr_image = Fl_PNG_Image(FLOOR).copy(cellSize, cellSize);
			break;

		case WALL:
			ptr_image = Fl_PNG_Image(IM_WALL).copy(cellSize, cellSize);
			break;

		case TP:
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::GREEN:
					ptr_image = Fl_PNG_Image(GREEN_TP).copy(cellSize, cellSize);
					break;
				case COLOR::PINK:
					ptr_image = Fl_PNG_Image(PINK_TP).copy(cellSize, cellSize);
					break;
				case COLOR::PURPLE:
					ptr_image = Fl_PNG_Image(PURPLE_TP).copy(cellSize, cellSize);
					break;
				default:
					break;
			}
			break;

		case TARGET:
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::NONE:
					ptr_image = Fl_PNG_Image(NONE_TARGET).copy(cellSize, cellSize);
					break;
				case COLOR::RED:
					ptr_image = Fl_PNG_Image(RED_TARGET).copy(cellSize, cellSize);
					break;
				case COLOR::ORANGE:
					ptr_image = Fl_PNG_Image(ORANGE_TARGET).copy(cellSize, cellSize);
					break;
				case COLOR::YELLOW:
					ptr_image = Fl_PNG_Image(YELLOW_TARGET).copy(cellSize, cellSize);
					break;
				case COLOR::GREEN:
					ptr_image = Fl_PNG_Image(GREEN_TARGET).copy(cellSize, cellSize);
					break;
				case COLOR::PURPLE:
					ptr_image = Fl_PNG_Image(PURPLE_TARGET).copy(cellSize, cellSize);
					break;
				case COLOR::BLUE:
					ptr_image = Fl_PNG_Image(BLUE_TARGET).copy(cellSize, cellSize);
					break;
				default:
					break;
			}
			break;

		case PLAYER:
			ptr_image = Fl_PNG_Image(IM_PLAYER).copy(cellSize, cellSize);
			break;

		case BOX:
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::NONE:
					ptr_image = Fl_PNG_Image(NONE_BOX).copy(cellSize, cellSize);
					break;
				case COLOR::RED:
					ptr_image = Fl_PNG_Image(RED_BOX).copy(cellSize, cellSize);
					break;
				case COLOR::ORANGE:
					ptr_image = Fl_PNG_Image(ORANGE_BOX).copy(cellSize, cellSize);
					break;
				case COLOR::YELLOW:
					ptr_image = Fl_PNG_Image(YELLOW_BOX).copy(cellSize, cellSize);
					break;
				case COLOR::GREEN:
					ptr_image = Fl_PNG_Image(GREEN_BOX).copy(cellSize, cellSize);
					break;
				case COLOR::PURPLE:
					ptr_image = Fl_PNG_Image(PURPLE_BOX).copy(cellSize, cellSize);
					break;
				case COLOR::BLUE:
					ptr_image = Fl_PNG_Image(BLUE_BOX).copy(cellSize, cellSize);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	// DRAW
	ptr_image->draw(display_pos.y, display_pos.x);
	delete ptr_image;
}


void DisplaySokoban::draw(){
	//draw la map 
	auto* other_cells = sokoban->getToutDeg(); //matrix map pointer
	Player* player = sokoban->getPlayerPTR(); 
	auto* boxes = sokoban->getTouBoxDeg(); //pointer vector box

	for (int i=0; i<other_cells->getRows(); i++){
		for (int j=0; j<other_cells->getCols(); j++){
			//if (player->getPos() == Point{i, j}) {continue;}
			drawACell(modelPosToDisplayPos(Point{i,j}), other_cells->at(i,j).get());
		}
	}

	drawACell(modelPosToDisplayPos(player->getPos()), player);
	//box
	for (auto& box: *boxes){ drawACell(modelPosToDisplayPos(box.getPos()), &box);}
}
