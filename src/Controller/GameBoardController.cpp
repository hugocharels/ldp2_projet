#include "../include.hpp"
#include "GameBoardController.hpp"


void GameBoardController::keyPressed(int key_code) {
	MOVE move = MOVE::INVALID;
	switch(key_code) {
		case 65362:
		case 'z':
			move = MOVE::UP;
			break;
		case 65364:
		case 's':
			move = MOVE::DOWN;
			break;
		case 65361:
		case 'q':
			move = MOVE::LEFT;
			break;
		case 65363:
		case 'd':
			move = MOVE::RIGHT;
			break;
	}
	this->state = this->model->inputPlayer(move);
}


void GameBoardController::mouseClick(Point mouse_loc) {
	this->state = this->model->inputPlayer(MOVE::INVALID);	
	Point pos = this->displayPosToBoardPos(mouse_loc);
	std::vector<MOVE> moves;
	this->model->canMovePlayerTo(moves, pos);
	if (not moves.empty()) { this->model->movePlayer(moves); }
	this->state = this->model->inputPlayer(MOVE::INVALID);    
}
