#ifndef _BOARD_H
#define _BOARD_H

#include <string>
#include <vector>

#include "matrix.h"
#include "moveable.h"
#include "configs.h"


class Board {

	Matrix<CELL> matrix;
	Player player;
	std::vector<Box> boxes;

	void boxHere(Point pos);

	bool canMoveUp();
	bool canMoveDown();
	bool canMoveLeft();
	bool canMoveRight();

public:

	Board() {}
	~Board()=default;

	void load(const std::string &file_path);

	void print();		// only in terminal

	bool play(MOVE move);

	bool win();
};


#endif