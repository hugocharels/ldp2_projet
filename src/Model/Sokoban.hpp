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
	int current_idx = 0;	//current level
	int select_idx = 0;
	
	std::string status;

public:

	Sokoban() { this->start(0); }
	~Sokoban()=default;
 	
	// PLAY
	void start(int idx);
 	GAME_STATE inputPlayer(MOVE move);
 	
	// GAME STATE
 	bool win() const { return board.win(); }
 	bool loose() const { return board.loose(); }
 	bool looseNoMoreStep() const { return step_limit <= board.getPlayer()->getSteps(); }

	// MOVE
 	void canMovePlayerTo(std::vector<MOVE>& moves, Point pos) const ;
 	void movePlayer(std::vector<MOVE>& moves);

	// FILES
	void save(int limit) { levels.saveBoard(board, limit); this->start(this->current_idx); }
	void resetBestScore() { best_score=0; this->levels.updateBestScore(this->current_idx, 0); }

	// GETTERS
	const std::string& getStatus() const { return status; }
	int getBestScore() const { return best_score; }
	int getStepLimit() const { return step_limit; }
	int getCurrentIdx() const { return current_idx; }
	int getSelectIdx() const { return select_idx; }

	// BOARD GETTERS
 	Player* getPlayer() { return board.getPlayer(); }
	Matrix<std::unique_ptr<Cell>>* getMap() { return board.getMap(); } 
	std::vector<Box>* getBoxes() { return board.getBoxes(); }
	Board* getBoard() { return &board; }

	// SETTERS
	void setSelectIdx(int inc) { select_idx = mod(select_idx+inc, levels.getSize()); }
	void setStatus(int code);

};

#endif