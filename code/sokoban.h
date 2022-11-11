#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "board.h"


class Sokoban {

	Board board;

public:

	Sokoban() {this->board.load(FILE_TEST);}
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	void changeState(MOVE move);
 	
 	bool win() { return board.win(); }

 	void draw();

};


#endif