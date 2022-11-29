#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>

#include "DisplaySokoban.h"
#include "../cell/include.h"
#include "../configs.h"
#include "../images.h"


void DisplaySokoban::drawACell(Point display_pos, Cell* cell){
	Fl_Box box = Fl_Box(display_pos.x, display_pos.y, cellSize, cellSize);
	Fl_PNG_Image* ptr_image;
	switch(cell->getType()) {
		case EMPTY:
			//Fl_PNG_Image ptr_image = new Fl_PNG_Image(FLOOR);
			break;

		case WALL:
			ptr_image = new Fl_PNG_Image(IM_WALL);
			break;

		case TP:
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::GREEN:
					ptr_image = new Fl_PNG_Image(GREEN_TP);
					break;
				case COLOR::PINK:
					ptr_image = new Fl_PNG_Image(PINK_TP);
					break;
				case COLOR::PURPLE:
					ptr_image = new Fl_PNG_Image(PURPLE_TP);
					break;
				default:
					break;
			}
			break;

		case TARGET:
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::NONE:
					ptr_image = new Fl_PNG_Image(NONE_TARGET);
					break;
				case COLOR::RED:
					ptr_image = new Fl_PNG_Image(RED_TARGET);
					break;
				case COLOR::ORANGE:
					ptr_image = new Fl_PNG_Image(ORANGE_TARGET);
					break;
				case COLOR::YELLOW:
					ptr_image = new Fl_PNG_Image(YELLOW_TARGET);
					break;
				case COLOR::GREEN:
					ptr_image = new Fl_PNG_Image(GREEN_TARGET);
					break;
				case COLOR::PURPLE:
					ptr_image = new Fl_PNG_Image(PURPLE_TARGET);
					break;
				case COLOR::BLUE:
					ptr_image = new Fl_PNG_Image(BLUE_TARGET);
					break;
				default:
					break;
			}
			break;

		case PLAYER:
			ptr_image = new Fl_PNG_Image(IM_PLAYER);
			break;

		case BOX:
			switch(dynamic_cast<ColorCell*>(cell)->getColor()) {
				case COLOR::NONE:
					ptr_image = new Fl_PNG_Image(NONE_BOX);
					break;
				case COLOR::RED:
					ptr_image = new Fl_PNG_Image(RED_BOX);
					break;
				case COLOR::ORANGE:
					ptr_image = new Fl_PNG_Image(ORANGE_BOX);
					break;
				case COLOR::YELLOW:
					ptr_image = new Fl_PNG_Image(YELLOW_BOX);
					break;
				case COLOR::GREEN:
					ptr_image = new Fl_PNG_Image(GREEN_BOX);
					break;
				case COLOR::PURPLE:
					ptr_image = new Fl_PNG_Image(PURPLE_BOX);
					break;
				case COLOR::BLUE:
					ptr_image = new Fl_PNG_Image(BLUE_BOX);
					break;
				default:
					break;
			}
			break;
		default:
			break;
		
		// DRAW
		box.image(ptr_image);
		box.redraw();

		delete ptr_image;
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

	drawACell(modelPosToDisplayPos(player->getPos()), player);
	//box
	for (auto& box: *boxes){ drawACell(modelPosToDisplayPos(box.getPos()), &box);}
}
