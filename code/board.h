#ifndef _BOARD_H
#define _BOARD_H

#include <string>
#include <vector>

#include "matrix.h"
#include "moveable.h"
#include "configs.h"


class Board {

	Matrix<CELL> map;
	Player player;
	std::vector<Box> boxes;

	bool inMap(int x, int y) const ;
	bool canPlayerMove(MOVE move);

public:

	Board() {}
	~Board()=default;

	void load(const std::string &file_path);

	void print();		// only in terminal

	bool play(MOVE move);

	bool win() const ;
};


#endif