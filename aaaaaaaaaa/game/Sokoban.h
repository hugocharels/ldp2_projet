#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "Board.h"
#include "Levels.h"

#include <string>


class Sokoban {

	Board board;
	Levels levels; 
	int step_limit;
	int best_score;
	std::string status = "You are playing level n";

	void setStatus(int code);

public:

	Sokoban() { this->restart(5); }
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	void inputPlayer(MOVE move);
 	
	void restart(int idx) { levels.createBoard(idx, this->board, this->best_score, this->step_limit); }

 	bool win() { return board.win(); }
 	
 	bool loose() { return board.loose(); }

 	bool looseNoMoreStep() { return step_limit <= board.getPlayerPTR()->getSteps(); }

 	void canMovePlayerTo(std::vector<MOVE>& moves, Point pos);

 	void movePlayer(std::vector<MOVE>& moves);


 	Player* getPlayerPTR() { return board.getPlayerPTR(); }

	auto* getToutDeg() { return board.getToutDeg(); } 

	auto* getTouBoxDeg() { return board.getTouBoxDeg(); }

	int getBestScore() { return best_score; }

	int getStepLimit() { return step_limit; }

	std::string getStatus() { return status; }

	//void setStatus(int code);

};


#endif