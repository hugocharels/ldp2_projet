#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "Board.h"

#include <string>


class Sokoban {

	Board board;
	std::string level;
	int step_limit;
	int best_score;

public:

	Sokoban() { this->restart(LEVEL1); }
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	void inputPlayer(MOVE move);
 	
 	void restart(const std::string &level) { this->load(level); this->board.print();}

 	bool win() { return board.win(); }
 	
 	bool loose() { return board.loose() or step_limit <= board.getPlayerPTR()->getSteps(); }

 	void canMovePlayerTo(std::vector<MOVE>& moves, Point pos);

 	void movePlayer(std::vector<MOVE>& moves);


	void load(const std::string &path);



 	Player* getPlayerPTR() { return board.getPlayerPTR(); }

	auto* getToutDeg() { return board.getToutDeg(); } 

	auto* getTouBoxDeg() { return board.getTouBoxDeg(); }

};


#endif