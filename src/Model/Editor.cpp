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
	auto* map = board->getToutDeg();

	std::cout << boxes << map << std::endl;

	switch(this->selected) {

		case EMPTY:
			//board->removeIfBox(pos)
			if (player->getPos() == pos) { return; }
			map->at(pos.x, pos.y) = std::make_unique<Cell>(EMPTY);
			break;
		
		case WALL:
			//board->removeIfBox(pos)
			if (player->getPos() == pos) { return; }
			map->at(pos.x, pos.y) = std::make_unique<Cell>(WALL);
			break;
		
		case TARGET:
			// pareil qu'au dessus mais get la color
			break;


		case TP:
			// pareil que target
			break;

		case PLAYER:
			if (board->boxHere(pos)) { break; }
			if (*map->at(pos.x, pos.y) == EMPTY) {	// peut que placé sur du vide atm
				std::cout << "player has been moved to " << pos.x << "/" << pos.y << std::endl;
				*player = Player{pos};
			}
			break;

		case BOX:
			// verif sur quoi tu la met + si y'en a déjà une la
			break;
			
	}

	std::cout << (char)selected << " : " << pos.x << "/" << pos.y << std::endl;

}
