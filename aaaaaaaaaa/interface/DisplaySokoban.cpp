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
	switch(cell->getType()) {
		case EMPTY:
			Fl_PNG_Image(FLOOR).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
			break;

		case WALL:
			Fl_PNG_Image(IM_WALL).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
			break;

		case TP:
			Fl_PNG_Image(FLOOR).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::GREEN:
					Fl_PNG_Image(GREEN_TP).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::PINK:
					Fl_PNG_Image(PINK_TP).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::PURPLE:
					Fl_PNG_Image(PURPLE_TP).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				default:
					break;
			}
			break;

		case TARGET:
			Fl_PNG_Image(FLOOR).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::NONE:
					Fl_PNG_Image(NONE_TARGET).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::RED:
					Fl_PNG_Image(RED_TARGET).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::ORANGE:
					Fl_PNG_Image(ORANGE_TARGET).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::YELLOW:
					Fl_PNG_Image(YELLOW_TARGET).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::GREEN:
					Fl_PNG_Image(GREEN_TARGET).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::PURPLE:
					Fl_PNG_Image(PURPLE_TARGET).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::BLUE:
					Fl_PNG_Image(BLUE_TARGET).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				default:
					break;
			}
			break;

		case PLAYER:
			Fl_PNG_Image(IM_PLAYER).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);;
			break;

		case BOX:
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::NONE:
					Fl_PNG_Image(NONE_BOX).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::RED:
					Fl_PNG_Image(RED_BOX).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::ORANGE:
					Fl_PNG_Image(ORANGE_BOX).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::YELLOW:
					Fl_PNG_Image(YELLOW_BOX).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::GREEN:
					Fl_PNG_Image(GREEN_BOX).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::PURPLE:
					Fl_PNG_Image(PURPLE_BOX).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				case COLOR::BLUE:
					Fl_PNG_Image(BLUE_BOX).copy(cellSize, cellSize)->draw(display_pos.y, display_pos.x);
					break;
				default:
					break;
			}
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
			//if (player->getPos() == Point{i, j}) {continue;}
			drawACell(modelPosToDisplayPos(Point{i,j}), other_cells->at(i,j).get());
		}
	}

	drawACell(modelPosToDisplayPos(player->getPos()), player);
	//box
	for (auto& box: *boxes){ drawACell(modelPosToDisplayPos(box.getPos()), &box);}
}
