#include "../include.hpp"
#include "Sokoban.hpp"


MOVE strToMOVE(std::string str) {
	if (str == "z") return MOVE::UP;
	if (str == "s") return MOVE::DOWN;
	if (str == "q") return MOVE::LEFT;
	if (str == "d") return MOVE::RIGHT;
	return MOVE::INVALID;
}


// PLAY

void Sokoban::start(int idx) { 
	current_idx= idx; 
	levels.createBoard(idx, this->board, this->best_score, this->step_limit); 
	status = "You are playing level " + std::to_string(current_idx); 
}


GAME_STATE Sokoban::inputPlayer(MOVE move)  {
	this->board.play(move);

	if (this->win()) {
		int win_step = board.getPlayer()->getSteps();
		if (this->best_score == 0 or win_step < this->best_score){
			this->levels.updateBestScore(this->current_idx, win_step);
			this->best_score=win_step;
			this->setStatus(1);
		} else{ this->setStatus(0); }
		return GAME_STATE::ENDGAME;
	} 
	else if (this->loose()) {
		this->setStatus(2);
		return GAME_STATE::ENDGAME;
	}
	else if (this->step_limit > 1 and this->looseNoMoreStep()){
		this->setStatus(3);
		return GAME_STATE::ENDGAME;			
	}
	return GAME_STATE::INGAME;
}


// MOVE

void Sokoban::canMovePlayerTo(std::vector<MOVE>& moves, Point pos) const {
	if (board.boxHere(pos)) { return; }

	// inspired by https://www.geeksforgeeks.org/shortest-distance-two-cells-matrix-grid/

	struct CellPosMove {
		Point pos;
		std::vector<MOVE> moves;
	};

	CellPosMove source{board.getPlayer()->getPos(), std::vector<MOVE>{}};
	auto* map = this->board.getMap();
	Matrix<char> visited{map->getRows(), map->getCols()};

	for (int i = 0; i < map->getRows(); i++) {
		for (int j = 0; j < map->getCols(); j++) {

			if ((map->at(i, j)->getType() == CELL::EMPTY or map->at(i, j)->getType() == CELL::TARGET) and not board.boxHere(Point{i, j})) { 
				visited.at(i, j) = 0;
			} else { 
				visited.at(i, j) = 1; 
			}
		}
	}

	std::queue<CellPosMove> q;
	q.push(source);
	visited.at(source.pos.x, source.pos.y) = 1;
	while (!q.empty()) {
		CellPosMove p = q.front();
		q.pop();
		// Destination found;
		if (p.pos == pos) {
			moves = p.moves;
			return;
		}
		// moving up
		if (p.pos.x - 1 >= 0 and not visited.at(p.pos.x - 1, p.pos.y)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(MOVE::UP);
			q.push(CellPosMove{Point{p.pos.x - 1, p.pos.y}, tmp});
			visited.at(p.pos.x - 1, p.pos.y) = 1;
		}
		// moving down
		if (p.pos.x + 1 < map->getRows() and not visited.at(p.pos.x + 1, p.pos.y)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(MOVE::DOWN);
			q.push(CellPosMove{Point{p.pos.x + 1, p.pos.y}, tmp});
			visited.at(p.pos.x + 1, p.pos.y) = 1;
		}
		// moving left
		if (p.pos.y - 1 >= 0 and not visited.at(p.pos.x, p.pos.y - 1)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(MOVE::LEFT);
			q.push(CellPosMove{Point{p.pos.x, p.pos.y - 1}, tmp});
			visited.at(p.pos.x, p.pos.y - 1) = 1;
		}
		// moving right
		if (p.pos.y + 1 < map->getCols() and not visited.at(p.pos.x, p.pos.y + 1)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(MOVE::RIGHT);
			q.push(CellPosMove{Point{p.pos.x, p.pos.y + 1}, tmp});
			visited.at(p.pos.x, p.pos.y + 1) = 1;
		}
	}
	moves = std::vector<MOVE>{};
}

GAME_STATE Sokoban::movePlayer(std::vector<MOVE>& moves) {
	for (auto &move : moves) {
		if (this->inputPlayer(move) == GAME_STATE::ENDGAME) { return GAME_STATE::ENDGAME; }
	} return GAME_STATE::INGAME;
}


// SETTER

void Sokoban::setStatus(int code){
	/**
	 * 0 = win
	 * 1 = new best score
	 * 2 = loose bc all boxes are blocked
	 * 3 = loose bc no more steps left
	**/
	switch(code) {
		case 0:
			this->status = "You win !";
			break;
		case 1:
			this->status = "You win and new best score !";
			break;
		case 2:
			this->status = "You lose ! (too much blocked boxes)";
			break;
		case 3:
			this->status = "You lose ! (no more steps left)";
			break;
		case 4:
			this->status = "You are in editing mode";
			break;
	}
}
