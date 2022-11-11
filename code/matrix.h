#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>

template<typename T>
class Matrix {

	class Table {
		
		T* table;
		int size;

	public:
		
		Table()=default;

		Table(Table &other)=default;

		~Table() {
			delete[] this->table;
		}

		void init(int size) {
			this->size = size;
			this->table = new T[this->size];
			for (int i=0; i<this->size; ++i) {
				this->table[i] = T{};
			}
			std::cout << table[0] << std::endl;
		}

		T &operator[](int y) {
			std::cout << size << " / " << y << std::endl;
			return this->table[y];
		}
	};

	Table* matrix;
	int rows;
	int cols;

public:

	Matrix(int rows=0, int cols=0):rows{rows},cols{cols} {
		this->matrix = new Table[this->cols];
		for (int i=0; i<this->cols; ++i) {
			this->matrix[i].init(this->rows);
		}
	}

	Matrix(Matrix &other)=default;

	~Matrix() {
		delete[] this->matrix;
	}

	Matrix<T>::Table &operator[](int x) {
		return this->matrix[x];
	}

	int getCols() { return this->cols; }
	int getRows() { return this->rows; }

};

#endif