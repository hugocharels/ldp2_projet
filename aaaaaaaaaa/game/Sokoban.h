#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "Board.h"


class Sokoban {

	Board board;

public:

	Sokoban() {this->board.load(LEVEL2); this->board.print();}
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	void inputPlayer(MOVE move);
 	
 	void restart() { this->board.reload(LEVEL1); this->board.print();}

 	bool win() { return board.win(); }

 	Player* getPlayerPTR() { return board.getPlayerPTR(); }

	auto* getToutDeg() { return board.getToutDeg(); } 

	auto* getTouBoxDeg() { return board.getTouBoxDeg(); }

};


#endif