#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "Board.h"

const std::string FILE_TEST = "aa";

class Sokoban {

	Board board;

public:

	Sokoban() {this->board.load(FILE_TEST); this->board.print();}
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	void inputPlayer(MOVE move);
 	
 	void restart() { this->board.reload(FILE_TEST); this->board.print();}

 	bool win() { return board.win(); }

};


#endif