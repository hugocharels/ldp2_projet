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
		}

		T &operator[](int y) {
			return this->table[y];
		}
	};

	Table* matrix;
	int rows;
	int cols;

	void init() {
		for (int i=0; i<this->cols; ++i) {
			this->matrix[i].init(this->rows);
		}
	}

public:

	Matrix(int rows=0, int cols=0):rows{rows},cols{cols} {
		this->matrix = new Table[this->cols];
		this->init();
	}

	Matrix(Matrix &other)=default;

	~Matrix() {
		delete[] this->matrix;
	}


	void operator=(Matrix<T> other) {
		this->rows = other.rows;
		this->cols = other.cols;
		init();
	}


	Matrix<T>::Table &operator[](int x) {
		return this->matrix[x];
	}

	int getCols() { return this->cols; }
	int getRows() { return this->rows; }

};

#endif