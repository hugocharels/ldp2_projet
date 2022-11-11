#ifndef _BOARD_H_
#define _BOARD_H_

#include <string>
#include "matrix.h"


class Board {

	Matrix<int> matrix;

public:

	Board()=default;
	~Board()=default;

	void load(std::string &file_path);

	void print();

};


#endif