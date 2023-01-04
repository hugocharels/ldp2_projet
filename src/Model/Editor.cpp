#include "../include.hpp"
#include "Editor.hpp"
#include "Board.hpp"


// PUBLIC

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
			board->removeIfBox(pos);
			if (player->getPos() == pos) { break; }
			map->at(pos.x, pos.y) = std::make_unique<Target>(this->getTargetColor());
			break;

		case TP:
			board->removeIfBox(pos);
			if (player->getPos() == pos) { break; }
			map->at(pos.x, pos.y) = std::make_unique<Teleporter>(this->getTeleporterColor());
			break;

		case PLAYER:
			board->removeIfBox(pos);
			if (map->at(pos.x, pos.y)->walkable()) {
				std::cout << "player has been moved to " << pos.x << "/" << pos.y << std::endl;
				*player = Player{pos};
			}
			break;

		case BOX:
			if (map->at(pos.x, pos.y)->walkable()) {
				board->removeIfBox(pos);
				boxes->push_back(Box{pos, this->getBoxColor()});
			}
			break;
	}
}


// PRIVATE

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

COLOR Editor::getTargetColor() const {
	switch(this->target_idx) {
		case 1: return COLOR::RED;
		case 2: return COLOR::ORANGE;
		case 3: return COLOR::YELLOW;
		case 4: return COLOR::GREEN;
		case 5: return COLOR::BLUE;
		case 6: return COLOR::PURPLE;
	} return COLOR::NONE;
}

COLOR Editor::getTeleporterColor() const {
	switch(this->tp_idx) {
		case 0: return COLOR::GREEN;
		case 1: return COLOR::PINK;
		case 2: return COLOR::PURPLE;
	} return COLOR::NONE;
}
