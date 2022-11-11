#include <iostream>
#include <string>

#include "sokoban.h"


MOVE strToMOVE(std::string str) {
	if (str == "z") return UP;
	if (str == "s") return DOWN;
	if (str == "q") return LEFT;
	if (str == "d") return RIGHT;
	return INVALID;
}


void Sokoban::start() {
	std::string input;
	this->board.print();
	while (true) {
		std::cout << "enter a move : ";
		std::cin >> input;
		if (this->board.play(strToMOVE(input))) {
			this->board.print();
			if (this->win()) {break;}
		}
	}
	std::cout << "gg" << std::endl;
}