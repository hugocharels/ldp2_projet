#include <iostream>
#include <string>

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

/*
std::vector<Point> possibleMove(auto &map, Point pos) {
	int x = pos.x, y = pos.y;
	std::vector<Point> moves;
	if (x+1 < map.getRows() and not map[x+1][y]) {moves.push_back(Point{x+1, y});}
	if (x-1 > 0 and not map[x-1][y]) {moves.push_back(Point{x-1, y});}
	if (y+1 < map.getCols() and not map[x][y+1]) {moves.push_back(Point{x, y+1});}
	if (y-1 > 0 and not map[x][y-1]) {moves.push_back(Point{x, y-1});}
	return moves;
}


std::vector<Point> searchPath(auto &map, Point pos, Point dest, std::vector<Point> moves) {
	if (moves.empty()) { moves.push_back(pos); }
	if (moves.back() == dest) { return moves; }

	for (auto &move : possibleMove(map, pos)) {

		if (moves.size() > 1 and moves[moves.size()-2] == move) {continue;}

		moves.push_back(move);
		searchPath(map, move, dest, moves);
		moves.pop_back();

	}

	return moves;
}

*/
void Sokoban::canMovePlayerTo(std::vector<MOVE>& moves, Point pos) {
	// do things
	moves.push_back(UP);
	std::cout << "suppose to tp " << pos.x << "/" << pos.y << std::endl;
}

void Sokoban::movePlayer(std::vector<MOVE>& moves) {
	Player* p = board.getPlayerPTR();
	for (auto &move : moves) {
		p->move(move);
	}
}
