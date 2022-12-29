#include "../include.hpp"
#include "BoardController.hpp"


void BoardController::keyPressed(int key_code) {
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
		case ' ':
			this->model->restart(this->model->getCurrentIdx());
	}
	this->model->inputPlayer(move);
}


void BoardController::mouseClick(Point mouse_loc) {
	this->model->inputPlayer(INVALID);	
	Point pos = this->displayPosToBoardPos(mouse_loc);
	std::vector<MOVE> moves;
	this->model->canMovePlayerTo(moves, pos);
	if (not moves.empty()) { this->model->movePlayer(moves); }
	this->model->inputPlayer(INVALID);    
}