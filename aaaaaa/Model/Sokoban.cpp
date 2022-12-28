#include "../include.hpp"
#include "Sokoban.hpp"


MOVE strToMOVE(std::string str) {
	if (str == "z") return UP;
	if (str == "s") return DOWN;
	if (str == "q") return LEFT;
	if (str == "d") return RIGHT;
	return INVALID;
}


void Sokoban::start() {
	std::string input;
	this->board.print();
	while (true) {
		std::cout << "enter a move : ";
		std::cin >> input;
		if (this->board.play(strToMOVE(input))) {
			this->board.print();
			if (this->win()) {
				std::cout << "gg" << std::endl;
				break;
			} else if (this->loose()) {
				std::cout << "rip" << std::endl;
				break;
			}
		}
	}
}


void Sokoban::inputPlayer(MOVE move)  {
	this->board.play(move);
	//this->board.print();
	if (this->win()) {
		this->setStatus(0);
		std::cout << "gg" << std::endl;
		//exit(0);
	} 
	else if (this->loose()) {
		this->setStatus(2);
		std::cout << "ripun" << std::endl;
		//exit(0);
	}
	else if (this->looseNoMoreStep()){
		this->setStatus(3);
		std::cout << "ripeu" << std::endl;
	}
}



void Sokoban::canMovePlayerTo(std::vector<MOVE>& moves, Point pos) {

	if (board.boxHere(pos)) { return; }

	struct CellPosMove {
		Point pos;
		std::vector<MOVE> moves;
	};

	CellPosMove source{board.getPlayerPTR()->getPos(), std::vector<MOVE>{}};

	auto* map = this->getToutDeg();

	Matrix<char> visited{map->getRows(), map->getCols()};

	for (int i = 0; i < map->getRows(); i++) {
		for (int j = 0; j < map->getCols(); j++) {

			if ((map->at(i, j)->getType() == EMPTY or map->at(i, j)->getType() == TARGET) and not board.boxHere(Point{i, j})) { 
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
			tmp.push_back(UP);
			q.push(CellPosMove{Point{p.pos.x - 1, p.pos.y}, tmp});
			visited.at(p.pos.x - 1, p.pos.y) = 1;
		}

		// moving down
		if (p.pos.x + 1 < map->getRows() and not visited.at(p.pos.x + 1, p.pos.y)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(DOWN);
			q.push(CellPosMove{Point{p.pos.x + 1, p.pos.y}, tmp});
			visited.at(p.pos.x + 1, p.pos.y) = 1;
		}

		// moving left
		if (p.pos.y - 1 >= 0 and not visited.at(p.pos.x, p.pos.y - 1)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(LEFT);
			q.push(CellPosMove{Point{p.pos.x, p.pos.y - 1}, tmp});
			visited.at(p.pos.x, p.pos.y - 1) = 1;
		}

		// moving right
		if (p.pos.y + 1 < map->getCols() and not visited.at(p.pos.x, p.pos.y + 1)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(RIGHT);
			q.push(CellPosMove{Point{p.pos.x, p.pos.y + 1}, tmp});
			visited.at(p.pos.x, p.pos.y + 1) = 1;
		}
	}
	moves = std::vector<MOVE>{};
}



void Sokoban::movePlayer(std::vector<MOVE>& moves) {
	Player* p = board.getPlayerPTR();
	for (auto &move : moves) {
		p->move(move);
	}
}


void Sokoban::restart(int idx) { 
	current_idx= idx; 
	levels.createBoard(idx, this->board, this->best_score, this->step_limit); 
	status = "You are playing level " + std::to_string(current_idx); 
}


void Sokoban::setStatus(int code){
	/*
	0 = win
	1 = new best score
	2 = loose bc all boxes are blocked
	3 = loose bc no more steps left
	*/
	switch(code) {
		case 0:
			status = "You win !";
			break;
		case 1:
			status = "New best score !";
			break;

		case 2:
			status = "You lose ! (all boxes are blocked)";
			break;
		case 3:
			status = "You lose ! (no more steps left)";
			break;
	}
}
