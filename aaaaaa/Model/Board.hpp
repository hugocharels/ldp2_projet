#ifndef _BOARD_HPP
#define _BOARD_HPP

#include <string>
#include <vector>
#include <memory>
#include <json/json.h>

#include "../configs.hpp"
#include "Matrix.hpp"
#include "Cell/include.hpp"


class Board {

	Matrix<std::unique_ptr<Cell>> map;
	Player player;
	std::vector<Box> boxes;


	bool inMap(int x, int y) const ;

	bool moveBoxOnMove(MOVE move);

	void movePlayerOnTp();

	bool canPlayerMove(MOVE move);

	bool canBoxMove(Box &box, MOVE move);

	bool blockedBox(const Box &box);

public:

	Board()=default;
	~Board()=default;

	// LOAD
	void loadMap(int rows, int cols, std::string &str_map);
	void loadBoxes(Json::Value &boxes_info);
	void loadPlayer(Point pos) { this->player = Player{pos}; }


	void print();		// only in terminal

	bool play(MOVE move);

	bool win() const ;

	bool loose();

	bool boxHere(Point pos) const ;

	Player* getPlayerPTR() { return &player; }

	auto* getToutDeg() { return &map; } 

	auto* getTouBoxDeg() { return &boxes; }

};


#endif