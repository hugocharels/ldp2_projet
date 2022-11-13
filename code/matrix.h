#ifndef _MATRIX_H
#define _MATRIX_H

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
		this->matrix = new Table[this->rows];
		for (int i=0; i<this->rows; ++i) {
			this->matrix[i].init(this->cols);
		}
	}

public:

	Matrix(int rows=0, int cols=0):rows{rows},cols{cols} {
		this->init();
	}

	Matrix(Matrix &other)=default;

	~Matrix() {
		delete[] this->matrix;
	}


	void operator=(Matrix<T> other) {
		this->rows = other.rows;
		this->cols = other.cols;
		this->init();
	}


	Matrix<T>::Table &operator[](int x) {
		return this->matrix[x];
	}

	int getCols() const { return this->cols; }
	int getRows() const { return this->rows; }

};

#endif