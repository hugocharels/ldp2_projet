#include "../include.hpp"
#include "GameBoardController.hpp"


void GameBoardController::keyPressed(int key_code) {
	MOVE move = INVALID;
	switch(key_code) {
		case 65362:
		case 'z':
			move = UP;
			break;
		case 65364:
		case 's':
			move = DOWN;
			break;
		case 65361:
		case 'q':
			move = LEFT;
			break;
		case 65363:
		case 'd':
			move = RIGHT;
			break;
	}
	this->state = this->model->inputPlayer(move);
}


void GameBoardController::mouseClick(Point mouse_loc) {
	this->state = this->model->inputPlayer(INVALID);	
	Point pos = this->displayPosToBoardPos(mouse_loc);
	std::vector<MOVE> moves;
	this->model->canMovePlayerTo(moves, pos);
	if (not moves.empty()) { this->model->movePlayer(moves); }
	this->state = this->model->inputPlayer(INVALID);    
}
