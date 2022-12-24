#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <json/json.h>

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
		std::cout << "gg" << std::endl;
		exit(0);
	} else if (this->loose()) {
		std::cout << "rip" << std::endl;
		exit(0);
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


void Sokoban::load(const std::string &path) {

	// Chargement du fichier JSON
	Json::Value root;
	Json::Reader reader;
	std::ifstream file(path);
	if (not reader.parse(file, root)) {
		// Erreur de parsing
		std::cerr << "Error parsing file" << std::endl;
		return;
	}

	// Accès aux différentes valeurs du fichier JSON
	int rows = root["size"]["x"].asInt();
	int cols = root["size"]["y"].asInt();

	Json::Value matrix = root["matrix"];
	std::string str_map = Json::FastWriter().write(matrix);	

	str_map.erase(str_map.begin());
	str_map.erase(str_map.end()-2);
	
	while (str_map.find(",") != std::string::npos) {
		str_map.replace(str_map.find(","), 1, "\n");
	}
	str_map.erase(std::remove(str_map.begin(), str_map.end(), '\"'), str_map.end());

	this->board.loadMap(rows, cols, str_map);

	this->board.loadBoxes(root["boxes"]);

	int player_pos_x = root["player_pos"]["x"].asInt();
	int player_pos_y = root["player_pos"]["y"].asInt();
	board.loadPlayer(Point{player_pos_x, player_pos_y});

	this->best_score = root["best_score"].asInt();
	this->step_limit = root["step_limit"].asInt();
}
