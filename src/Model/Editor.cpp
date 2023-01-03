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

	Board* board = this->model->getBoard();

	if (not board->inMap(pos.x, pos.y)) { return; }

	auto* boxes = board->getTouBoxDeg();
	auto* player = board->getPlayerPTR();
	auto* matrix = board->getToutDeg();

	std::cout << boxes << matrix << std::endl;

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
			*player = Player{pos};
			break;

		case BOX:
			break;
			
	}

	std::cout << (char)selected << " : " << pos.x << "/" << pos.y << std::endl;

}
