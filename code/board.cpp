#include <iostream>
#include <fstream>
#include <string.h>

#include "board.h"
#include "configs.h"


template<typename T>
bool contains(T &contener, Point pos) {
	for (auto &i : contener) {
		if (pos == i.getPos()) {
			return true;
		}
	}
	return false;
}


CELL charToCELL(char c) {
	if (c == '#') return WALL;
	if (c == '@') return TARGET;
	return EMPTY;
}


void Board::load(const std::string &file_path) {
	std::string content = "";
	std::string line = "";
	std::ifstream file (file_path);
	int i = 0, j = 0;
	if (file.is_open()) {
		while (getline(file, line)) { 
			content += line + "\n";
			++i;
			if ((int)line.size() > j) {j= line.size();}
		}
		file.close();
	} else {
		std::cerr << "Can not open the file '" << file_path << "'" << std::endl;
	}
	std::cout << content << std::endl;
	this->matrix = Matrix<CELL>{i, j};
	i = 0, j = 0;
	for (auto c : content) {
		std::cout << i << " / " << j << std::endl;
		if (c == '\n') {++j; i=0; continue;}
		if (c == 'P') {this->player = Player(Point{i,j});}
		else if (c == 'B') {this->boxes.push_back(Box(Point{i,j}));}
		this->matrix[i][j] = EMPTY;
		if (c == '#' or c == '@') {this->matrix[i][j] = charToCELL(c);}
		++i;
	}
	std::cout << "ah nan" << std::endl;
}



//print verifie pour chaque case de la matrice MAP, si il n'y aurait pas un objet moveable (box ou player)
//si c'est le cas, un caractère correspondant est mis là

void Board::print(){
	std::string to_print = "";

	for (int i=0; i<this->matrix.getCols(); i++) {
	    for (int j=0; j<this->matrix.getRows(); j++) {
			if (this->player.getPos() == Point{i,j}) {
				to_print += "P";
			}
			else if (contains(this->boxes, Point{i,j})) {
				to_print += "B";
			}
			else {
				to_print += this->matrix[i][j];
			}
			to_print += "\n";
		}
	}		
	std::cout<<to_print<<std::endl;
}


bool Board::validMove(MOVE move) {
	if (move == INVALID) return false;
	return true;
}

bool Board::play(MOVE move) {
	if (this->validMove(move)) {
		if (move == UP and player.canGoUp()) {player.move(UP);}
		else if (move == DOWN and player.canGoDown()) {player.move(DOWN);}
		else if (move == LEFT and player.canGoLeft()) {player.move(LEFT);}
		else if (move == RIGHT and player.canGoRight()) {player.move(RIGHT);}
		return true;
	}
	std::cout << "invalid move" << std::endl;
	return false;
}


bool Board::win() {
	for (auto &box : this->boxes) {
		if (not box.onTarget()) {return false;}
	} return true;
}
