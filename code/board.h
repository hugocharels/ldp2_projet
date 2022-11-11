#ifndef _BOARD_H
#define _BOARD_H

#include <string>
#include <vector>
#include "matrix.h"


class Board {

	Matrix<CELL> matrix;
	Player player;
	std::vector<Box> boxes;

public:

	Board()=default;
	~Board()=default;

	void load(std::string &file_path);

	void print();

};


#endif