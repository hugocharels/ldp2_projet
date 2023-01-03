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
			board->removeIfBox(pos);
			if (player->getPos() == pos) { break; }
			map->at(pos.x, pos.y) = std::make_unique<Cell>(EMPTY);
			break;
		
		case WALL:
			board->removeIfBox(pos);
			if (player->getPos() == pos) { break; }
			map->at(pos.x, pos.y) = std::make_unique<Cell>(WALL);
			break;
		
		case TARGET:
			// pareil qu'au dessus mais get la color
			if (board->boxHere(pos)) { break; }
			break;


		case TP:
			// pareil que target
			if (board->boxHere(pos)) { break; }
			break;

		case PLAYER:
			if (board->boxHere(pos)) { break; }
			if (map->at(pos.x, pos.y)->walkable()) {
				std::cout << "player has been moved to " << pos.x << "/" << pos.y << std::endl;
				*player = Player{pos};
			}
			break;

		case BOX:
			// verif sur quoi tu la met + si y'en a déjà une la
			if (map->at(pos.x, pos.y)->walkable()) {
				board->removeIfBox(pos);
				boxes->push_back(Box{pos, this->getBoxColor()});
			}
			break;
	}

	std::cout << (char)selected << " : " << pos.x << "/" << pos.y << std::endl;

}


COLOR Editor::getBoxColor() const {
	switch(this->box_idx) {
		case 1: return COLOR::RED;
		case 2: return COLOR::ORANGE;
		case 3: return COLOR::YELLOW;
		case 4: return COLOR::GREEN;
		case 5: return COLOR::BLUE;
		case 6: return COLOR::PURPLE;
	} return COLOR::NONE;
}

