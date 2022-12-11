#include <iostream>
#include <string>
#include <vector>
#include <queue>

#include "Sokoban.h"
#include "../configs.h"


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
			if (this->win()) {break;}
		}
	}
	std::cout << "gg" << std::endl;
}


void Sokoban::inputPlayer(MOVE move)  {
	this->board.play(move);
	//this->board.print();
	if (this->win()) {
		std::cout << "gg" << std::endl;
		exit(0);
	}
}



void Sokoban::canMovePlayerTo(std::vector<MOVE>& moves, Point pos) {

	struct CellPosMove {
		Point pos;
		std::vector<MOVE> moves;
	};

	CellPosMove source{board.getPlayerPTR()->getPos(), std::vector<MOVE>{}};

	auto* map = this->getToutDeg();

	Matrix<char> visited{map->getRows(), map->getCols()};

	for (int i = 0; i < map->getRows(); i++) {
		for (int j = 0; j < map->getCols(); j++) {

			if (map->at(i, j)->walkable() and map->at(i, j)->getType() != TP and not board.boxHere(Point{i, j})) { 
				visited.at(i, j) = 1;
			} else { 
				visited.at(i, j) = 0; 
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
			q.push(CellPosMove(Point{p.pos.x - 1, p.pos.y}, tmp));
			visited.at(p.pos.x - 1, p.pos.y) = 1;
		}

		// moving down
		if (p.pos.x + 1 < map->getRows() and not visited.at(p.pos.x + 1, p.pos.y)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(DOWN);
			q.push(CellPosMove(Point{p.pos.x + 1, p.pos.y}, tmp));
			visited.at(p.pos.x + 1, p.pos.y) = 1;
		}

		// moving left
		if (p.pos.y - 1 >= 0 and not visited.at(p.pos.x, p.pos.y - 1)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(LEFT);
			q.push(CellPosMove(Point{p.pos.x, p.pos.y - 1}, tmp));
			visited.at(p.pos.x, p.pos.y - 1) = 1;
		}

		// moving right
		if (p.pos.y + 1 < map->getCols() and not visited.at(p.pos.x, p.pos.y + 1)) {
			std::vector<MOVE> tmp = p.moves;
			tmp.push_back(RIGHT);
			q.push(CellPosMove(Point{p.pos.x, p.pos.y + 1}, tmp));
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
