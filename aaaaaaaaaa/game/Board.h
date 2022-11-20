#ifndef _BOARD_H
#define _BOARD_H

#include <string>
#include <vector>

#include "Matrix.h"
#include "../cell/include.h"
#include ".../configs.h"


class Board {

	Matrix<Cell> map;
	Player player;
	std::vector<Box> boxes;

	bool inMap(int x, int y) const ;

	Point getNextPos(Moveable &obj, MOVE move);

	bool MoveboxOnMove(MOVE move);

	bool canPlayerMove(MOVE move);

	bool canBoxMove(Box &box, MOVE move);

public:

	Board() {}
	~Board()=default;

	void load(const std::string &file_path);

	void reload(const std::string &file_path) {
		this->boxes.clear();
		this->load(file_path);
	}

	void print();		// only in terminal

	bool play(MOVE move);

	bool win() const ;

};


#endif