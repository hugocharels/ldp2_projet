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
	this->map = Matrix<CELL>{i, j};
	i = 0, j = 0;
	for (auto c : content) {
		if (c == '\n') {++j; i=0; continue;}
		if (c == 'P') {this->player = Player(Point{i,j});}
		else if (c == 'B') {this->boxes.push_back(Box(Point{i,j}));}
		this->map[i][j] = EMPTY;
		if (c == '#' or c == '@') {this->map[i][j] = charToCELL(c);}
		++i;
	}
}



//print verifie pour chaque case de la matrice MAP, si il n'y aurait pas un objet moveable (box ou player)
//si c'est le cas, un caractère correspondant est mis là

void Board::print() {
	std::string to_print = "";

	for (int i=0; i<this->map.getCols(); i++) {
	    for (int j=0; j<this->map.getRows(); j++) {
			if (this->player.getPos() == Point{i,j}) {
				to_print += "P";
			}
			else if (contains(this->boxes, Point{i,j})) {
				to_print += "B";
			}
			else {
				to_print += this->map[i][j];
			}
		}
		to_print += "\n";
	}		
	std::cout<<to_print<<std::endl;
}


bool Board::inMap(int x, int y) const {
	return x > 0 and x < this->map.getRows()-1 and y > 0 and y < this->map.getCols()-1 ;
}


bool Board::canPlayerMove(MOVE move) {
	int x = this->player.getPos().x;
	int y = this->player.getPos().y;
	if (move == UP) { x--; }
	else if (move == DOWN) { x++; }
	else if (move == LEFT) { y--; }
	else if (move == RIGHT) { y++; }
	if (not this->inMap(x, y)) { return false; }
	return this->map[x][y] == EMPTY;
}


bool Board::play(MOVE move) {
	if (move == INVALID) {std::cout << "invalid move" << std::endl; return false;}
	if (this->canPlayerMove(move)) {
		player.move(UP);
	}
	return true;
}


bool Board::win() const {
	for (auto &box : this->boxes) {
		if (not box.onTarget()) {return false;}
	} return true;
}
