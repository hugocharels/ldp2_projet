#include <iostream>
#include <fstream>
#include <string.h>
#include <tuple>
#include <memory>

#include "Board.h"
#include "../configs.h"



Point getNextPos(MoveableCell &obj, MOVE move) {
	int x = obj.getPos().x;
	int y = obj.getPos().y;
	if (move == UP) { x--; }
	else if (move == DOWN) { x++; }
	else if (move == LEFT) { y--; }
	else if (move == RIGHT) { y++; }
	return Point{x, y};
}


// public 

Board::~Board() {
	for (int i=0; i<this->map.getRows(); i++) {
	    for (int j=0; j<this->map.getCols(); j++) {
	    	delete this->map.at(i, j).get();
	    }
	}
}


void Board::load(const std::string &file_path) {
	std::string content = "";
	std::string line = "";
	std::ifstream file (file_path);
	//get n colonne & n line
	int rows, cols;
	getline(file, line);
	rows = stoi(line);
	getline(file, line);
	cols = stoi(line);

	//load map
	if (file.is_open()) {
		for (int k=0; k<rows; k++){ 
			getline(file, line);
			content += line + "\n";
		}
	} else {
		std::cerr << "Can not open the file '" << file_path << "'" << std::endl;
	}

	std::vector<std::tuple<int, int, char, Teleporter*>> tp_vector;

	this->map.resize(rows, cols);
	int i = 0, j = 0;		//actual pos
	for (auto c : content) {
		if (c == '\n') { ++i; j=0; continue; }
		if (c == WALL) { this->map.at(i, j) = std::make_unique<Cell>(Cell{WALL}); }
		else if (c == EMPTY) { this->map.at(i, j) = std::make_unique<Cell>(Cell{EMPTY}); }
		else if (isdigit(c)) { this->map.at(i, j) = std::make_unique<Target>(Target{charToColor(c)}); }
		else { 
			this->map.at(i, j) = std::make_unique<Teleporter>(Teleporter{charToColor(c)});
			auto tp_info = std::make_tuple(i, j, c, dynamic_cast<Teleporter*>(this->map.at(i, j).get()));
			tp_vector.push_back(tp_info);
		} //teleporter chiant (dico ou constructeur desti à nulle)
		++j;
	}

	//teleporter association destination
	while (not tp_vector.empty()) {
		auto current = tp_vector.back();
		tp_vector.pop_back();
		int idx = 0;
		for (auto &elem : tp_vector) {
			if (std::get<2>(elem) == std::get<2>(current)) {
				std::get<3>(current)->setDestination(Point{std::get<0>(elem),std::get<1>(elem)});
				std::get<3>(elem)->setDestination(Point{std::get<0>(current),std::get<1>(current)});
				tp_vector.erase(tp_vector.begin()+idx);
				break;
			}
			idx++;
		}
	}

	this->loadBoxes(file);

	file.close();
}



//print verifie pour chaque case de la matrice MAP, si il n'y aurait pas un objet moveable (box ou player)
//si c'est le cas, un caractère correspondant est mis là

void Board::print() {
	std::string to_print = "";
	for (int i=0; i<this->map.getRows(); i++) {
	    for (int j=0; j<this->map.getCols(); j++) {
			if (this->player.getPos() == Point{i,j}) {
				to_print += "P";
			} else if (this->boxHere(Point{i,j})) {
				to_print += "B";
			} else {
				to_print += this->map.at(i, j)->getType();
			}
		}
		to_print += "\n";
	}
	std::cout<<to_print<<std::endl;
}


bool Board::play(MOVE move) {
	if (move == INVALID) {std::cout << "invalid move" << std::endl; return false;}
	if (this->canPlayerMove(move)) {
		if (this->moveBoxOnMove(move)) {
			player.move(move);
			this->movePlayerOnTp();
		}
	}
	return true;
}

bool Board::win() const {
	for (auto &box : this->boxes) {
		if (not box.onTarget()) { return false; }
	} return true;
}




// private

void Board::loadBoxes(auto &file) {
	std::string line="";
	while (getline(file, line)) {
		int x=0,y=0;
		std::string str_pos = "";
		for (auto elem : line){
			if (isdigit(elem)) { str_pos += elem; }
			else if (elem == ',') { 
				x = stoi(str_pos);
				str_pos = "";
			}
			else if (elem == '-') { 
				y = stoi(str_pos); 
				this->boxes.push_back(Box{Point{x,y}, charToColor(line[line.length()-1])});		//dernier elem est la couleur en chiffre
				break;
			}
			else if (elem == '*') {
				y = stoi(str_pos);
				this->player = Player{{x,y}};
			}
		}
	}
}

bool Board::inMap(int x, int y) const {
	return x > 0 and x < this->map.getRows()-1 and y > 0 and y < this->map.getCols()-1 ;
}

bool Board::boxHere(Point pos) {
	for (auto &box : this->boxes) {
		if (pos == box.getPos()) {
			return true;
		}
	}
	return false;
}


bool Board::canPlayerMove(MOVE move) {
	Point next_pos = getNextPos(this->player, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y)) { return false; }
	return this->map.at(x, y)->walkable();
}

bool Board::canBoxMove(Box &box, MOVE move) {
	Point next_pos = getNextPos(box, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y) or this->boxHere(Point{x, y})) { return false; }
	return this->map.at(x, y)->walkable();
}

bool Board::moveBoxOnMove(MOVE move) {
	Point next_pos = getNextPos(this->player, move);
	for (auto &box : this->boxes) {
		if (box.getPos() == next_pos) {
			if (canBoxMove(box, move)) {
				box.move(move);
				Point box_pos = box.getPos();
				if (*(this->map.at(box_pos.x, box_pos.y)) == TARGET) {
					if (dynamic_cast<Target*>(this->map.at(box_pos.x, box_pos.y).get())->getColor() == box.getColor()) {
						box.setTarget(true);
					} else { box.setTarget(false); }
				} else { box.setTarget(false); }
				return true;
			} else { return false; }
		}
	} return true;
}

void Board::movePlayerOnTp() {
	int x = this->player.getPos().x;
	int y = this->player.getPos().y;

	if (*(this->map.at(x, y)) == TP) {
		Point tp_pos = dynamic_cast<Teleporter*>(this->map.at(x, y).get())->getTpPos();
		if (not this->boxHere(tp_pos)) {
			this->player.tp(tp_pos);
		}
	}
}

