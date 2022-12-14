#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "Board.h"


class Sokoban {

	Board board;
	int step_limit;
	int best_score;

public:

	Sokoban() {this->board.load(LEVEL1); this->board.print();}
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	void inputPlayer(MOVE move);
 	
 	void restart(const std::string &level) { this->board.load(level); this->board.print();}

 	bool win() { return board.win(); }
 	
 	bool loose() { return board.loose(); }

 	void canMovePlayerTo(std::vector<MOVE>& moves, Point pos);

 	void movePlayer(std::vector<MOVE>& moves);


 	Player* getPlayerPTR() { return board.getPlayerPTR(); }

	auto* getToutDeg() { return board.getToutDeg(); } 

	auto* getTouBoxDeg() { return board.getTouBoxDeg(); }

};


#endif