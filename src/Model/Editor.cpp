#include "../include.hpp"
#include "Editor.hpp"
#include "Board.hpp"


void Editor::selectElem(CELL cell) { 
	if (cell == selected) {
		this->is_selected = not this->is_selected;
	} else {
		this->selected = cell;
		this->is_selected = true;
	}
}


void Editor::placeElem(Point pos) {
	if (not is_selected) { return; }
	
	auto* boxes = this->model->getTouBoxDeg();
	auto* player = this->model->getPlayerPTR();
	auto* matrix = this->model->getToutDeg();

	switch(this->selected) {

		case EMPTY:
			break;
		
		case WALL:
			break;
		
		case TARGET:
			break;

		case TP:
			break;

		case PLAYER:
			break;

		case BOX:
			break;
			
	}

	std::cout << (char)selected << " : " << pos.x << "/" << pos.y << std::endl;

}
