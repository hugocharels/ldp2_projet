#ifndef _MATRIX_HPP
#define _MATRIX_HPP

#include <vector>


template<typename T>
class Matrix {

	std::vector<std::vector<T>> matrix;
	int rows;
	int cols;

public:

	Matrix(int rows=0, int cols=0):rows{rows},cols{cols} {
		if (rows > 0 and cols > 0) {this->resize(rows, cols);}
	}

	void resize(int rows, int cols) {
		this->matrix = std::vector<std::vector<T>>(rows);
		this->rows = rows;
		this->cols = cols;
		for (auto &vect : this->matrix) {
			vect = std::vector<T>(cols);
		}
	}

	T& at(int x, int y) {
		return this->matrix[x][y];
	}

	int getRows() const { return this->rows; }
	int getCols() const { return this->cols; }

};

#endif