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
	this->matrix = Matrix<CELL>{i, j};
	i = 0, j = 0;
	for (auto c : content) {
		if (c == '\n') {++j; i=0; continue;}
		if (c == 'P') {this->player = Player(Point{i,j});}
		else if (c == 'B') {this->boxes.push_back(Box(Point{i,j}));}
		this->matrix[i][j] = EMPTY;
		if (c == '#' or c == '@') {this->matrix[i][j] = charToCELL(c);}
		++i;
	}
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
		}
		to_print += "\n";
	}		
	std::cout<<to_print<<std::endl;
}





bool Board::canGoUp() {
	int x, y;
	x = this->player.position.x;
	y = this->player.position.y;
	if (x > 0 and this->matrix[x-1][y] != WALL) {
		for (auto &box : this->boxes) {
			if (box.position == Point{x-1, y}) {
				if (canMoveUp(box)) {
					moveBox(UP);
					return true;
				}
			} else {return false;}
		}
	} return false;
}

bool Board::canGoDown() {

}
bool Board::canGoLeft() {

}
bool Board::canGoRight() {

}


bool Board::play(MOVE move) {
	if (move == INVALID) {std::cout << "invalid move" << std::endl; return false;}
	else if (move == UP and canPlayerGoUp()) {player.move(UP);}
	else if (move == DOWN and player.canPlayerGoDown()) {player.move(DOWN);}
	else if (move == LEFT and player.canPlayerGoLeft()) {player.move(LEFT);}
	else if (move == RIGHT and player.canPlayerGoRight()) {player.move(RIGHT);}
	return true;
}


bool Board::win() {
	for (auto &box : this->boxes) {
		if (not box.onTarget()) {return false;}
	} return true;
}
