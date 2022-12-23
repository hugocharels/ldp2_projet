#ifndef _BOARD_H
#define _BOARD_H

#include <string>
#include <vector>
#include <memory>

#include "Matrix.h"
#include "../cell/include.h"
#include "../configs.h"


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

	Board() {}
	~Board();

	// LOAD
	void loadMap(int rows, int cols, std::string &str_map);
	void loadBoxes(auto &boxes_info);
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