#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "Board.h"


class Sokoban {

	Board board;

public:

	Sokoban() {this->board.load(LEVEL1); this->board.print();}
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	void inputPlayer(MOVE move);
 	
 	void restart() { this->board.reload(LEVEL1); this->board.print();}

 	bool win() { return board.win(); }

};


#endif