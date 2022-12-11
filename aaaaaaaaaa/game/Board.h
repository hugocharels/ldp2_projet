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

	// LOAD
	void loadBoxes(auto &file);


	bool inMap(int x, int y) const ;

	bool moveBoxOnMove(MOVE move);

	void movePlayerOnTp();

	bool canPlayerMove(MOVE move);

	bool canBoxMove(Box &box, MOVE move);

	bool blockedBox(const Box &box) const ;

public:

	Board() {}
	~Board();

	void load(const std::string &file_path);

	void reload(const std::string &file_path) {
		this->boxes.clear();
		this->load(file_path);
	}

	void print();		// only in terminal

	bool play(MOVE move);

	bool win() const ;

	bool loose() const;

	bool boxHere(Point pos) const ;

	Player* getPlayerPTR() { return &player; }

	auto* getToutDeg() { return &map; } 

	auto* getTouBoxDeg() { return &boxes; }

};


#endif