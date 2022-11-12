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
			//j= line.size();
		}
		file.close();
	} else {
		std::cerr << "Can not open the file '" << file_path << "'" << std::endl;
	}
	std::cout << content << std::endl;
	this->map = Matrix<CELL>{i, j};
	i = 0, j = 0;
	for (auto c : content) {
		std::cout<<c<<" "<<i<<" "<<j<<std::endl;
		if (c == '\n') {++i; j=0; continue;}
		if (c == 'P') {this->player = Player(Point{i,j});}
		else if (c == 'B') {this->boxes.push_back(Box(Point{i,j}));}
		this->map[i][j] = EMPTY;
		if (c == '#' or c == '@') {this->map[i][j] = charToCELL(c);}
		++j;
	}
}



//print verifie pour chaque case de la matrice MAP, si il n'y aurait pas un objet moveable (box ou player)
//si c'est le cas, un caractère correspondant est mis là

void Board::print() {
	std::string to_print = "";

	std::cout<<map.getRows()<<std::endl;
	std::cout<<map.getCols()<<std::endl;
	std::cout<<map[9][0]<<std::endl;
	for (int i=0; i<this->map.getRows(); i++) {
	    for (int j=0; j<this->map.getCols(); j++) {
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


Point Board::getNextPos(Moveable &obj, MOVE move) {
	int x = obj.getPos().x;
	int y = obj.getPos().y;
	if (move == UP) { x--; }
	else if (move == DOWN) { x++; }
	else if (move == LEFT) { y--; }
	else if (move == RIGHT) { y++; }
	return Point{x, y};
}


bool Board::canPlayerMove(MOVE move) {
	Point next_pos = this->getNextPos(this->player, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y)) { return false; }
	return this->map[x][y] == EMPTY or this->map[x][y] == TARGET;
}

bool Board::canBoxMove(Box &box, MOVE move) {
	Point next_pos = this->getNextPos(box, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y)) { return false; }
	return this->map[x][y] == EMPTY or this->map[x][y] == TARGET;
}

bool Board::boxOnMove(MOVE move) {
	Point next_pos = this->getNextPos(this->player, move);
	for (auto &box : this->boxes) {
		if (box.getPos() == next_pos) {
			return true;
		}
	} return false;
}


bool Board::play(MOVE move) {
	if (move == INVALID) {std::cout << "invalid move" << std::endl; return false;}
	if (this->canPlayerMove(move)) {
		if (this->boxOnMove(move)) {
			std::cout << "hum box here" << std::endl;
			Point next_pos = this->getNextPos(this->player, move);
			for (auto &box : this->boxes) {
				if (box.getPos() == next_pos) {
					if (canBoxMove(box, move)) { 
						box.move(move); 
						player.move(move);
						Point box_pos = box.getPos();
						if (this->map[box_pos.x][box_pos.y] == TARGET) { 
							box.setTarget(true);
						}
						else {
							box.setTarget(false);
						}
						

					}
				}
			}
		} else {
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
