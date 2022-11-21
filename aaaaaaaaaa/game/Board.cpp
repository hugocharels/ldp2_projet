#include <iostream>
#include <fstream>
#include <string.h>

#include "Board.h"
#include "../configs.h"


template<typename T>
bool contains(T &contener, Point pos) {
	for (auto &i : contener) {
		if (pos == i.getPos()) {
			return true;
		}
	}
	return false;
}



void Board::load(const std::string &file_path) {
	std::cout << file_path << std::endl;
	int rows = 4, cols = 4;
	this->map = Matrix<Cell>{rows, cols};
	std::string content{"####\n#--#\n#1-#\n####"};
	int i = 0, j = 0;
	for (auto c : content) {
		std::cout << c ;
		if (c == '\n') { ++i; j=0; continue; }
		if (c == '#') { this->map[i][j] = Cell{'#'}; }
		else if (c == '-') { this->map[i][j] = Cell{}; }
		else if (isdigit(c)) { this->map[i][j] = Target{}; }
		++j;
	}
	this->player = Player{Point{1, 1}};
	this->boxes.push_back(Box(Point{2, 2}));
}



//print verifie pour chaque case de la matrice MAP, si il n'y aurait pas un objet moveable (box ou player)
//si c'est le cas, un caractère correspondant est mis là

void Board::print() {
	std::string to_print = "";
	for (int i=0; i<this->map.getRows(); i++) {
	    for (int j=0; j<this->map.getCols(); j++) {
			if (this->player.getPos() == Point{i,j}) {
				to_print += "P";
			} else if (contains(this->boxes, Point{i,j})) {
				to_print += "B";
			} else {
				to_print += this->map[i][j].getType();
			}
		}
		to_print += "\n";
	}
	std::cout<<to_print<<std::endl;
}


bool Board::inMap(int x, int y) const {
	return x > 0 and x < this->map.getRows()-1 and y > 0 and y < this->map.getCols()-1 ;
}


Point getNextPos(MoveableCell &obj, MOVE move) {
	int x = obj.getPos().x;
	int y = obj.getPos().y;
	if (move == UP) { x--; }
	else if (move == DOWN) { x++; }
	else if (move == LEFT) { y--; }
	else if (move == RIGHT) { y++; }
	return Point{x, y};
}


bool Board::canPlayerMove(MOVE move) {
	Point next_pos = getNextPos(this->player, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y)) { return false; }
	return this->map[x][y] == EMPTY or this->map[x][y] == TARGET;
}

bool Board::canBoxMove(Box &box, MOVE move) {
	Point next_pos = getNextPos(box, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y) or contains(this->boxes, Point{x, y})) { return false; }
	return this->map[x][y] == EMPTY or this->map[x][y] == TARGET;
}

bool Board::MoveboxOnMove(MOVE move) {
	Point next_pos = getNextPos(this->player, move);
	for (auto &box : this->boxes) {
		if (box.getPos() == next_pos) {
			if (canBoxMove(box, move)) {
				box.move(move);
				Point box_pos = box.getPos();
				if (this->map[box_pos.x][box_pos.y] == TARGET) { 
					box.setTarget(true);
				} else {
					box.setTarget(false);
				}
				return true;
			} else { return false; }
		}
	} return true;
}


bool Board::play(MOVE move) {
	if (move == INVALID) {std::cout << "invalid move" << std::endl; return false;}
	if (this->canPlayerMove(move)) {
		if (this->MoveboxOnMove(move)) {
			player.move(move);
		}
	}
	return true;
}


bool Board::win() const {
	for (auto &box : this->boxes) {
		if (not box.onTarget()) { return false; }
	} return true;
}
