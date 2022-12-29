#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "../include.hpp"
#include "Board.hpp"
#include "Levels.hpp"


class Sokoban {

	Board board;
	Levels levels; 
	int step_limit;
	int best_score;
	int current_idx = 0; //current level
	int select_idx = 0;
	std::string status;

	void setStatus(int code);

public:

	Sokoban() { this->restart(0); }
	~Sokoban()=default;
 	
	void start();	// only in terminal

 	GAME_STATE inputPlayer(MOVE move);
 	
	void restart(int idx);

 	bool win() { return board.win(); }
 	bool loose() { return board.loose(); }
 	bool looseNoMoreStep() { return step_limit < board.getPlayerPTR()->getSteps(); }

 	void canMovePlayerTo(std::vector<MOVE>& moves, Point pos);
 	void movePlayer(std::vector<MOVE>& moves);


 	Player* getPlayerPTR() { return board.getPlayerPTR(); }
	auto* getToutDeg() { return board.getToutDeg(); } 
	auto* getTouBoxDeg() { return board.getTouBoxDeg(); }

	int getBestScore() { return best_score; }
	int getStepLimit() { return step_limit; }

	int getCurrentIdx() { return current_idx; }
	int getSelectIdx() { return select_idx; }
	
	std::string getStatus() { return status; }

	void setSelectIdx(int inc) { select_idx = mod(select_idx+inc, levels.getSize()) ; std::cout<<select_idx<<std::endl;}

	void resetBestScore() { this->levels.updateBestScore(this->current_idx, 0); }

};


#endif