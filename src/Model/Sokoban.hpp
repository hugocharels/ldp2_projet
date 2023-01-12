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
	int current_idx = 0;	// current level
	int select_idx = 0;		// next level to load
	
	std::string status;

public:

	Sokoban() { this->start(0); }
	~Sokoban()=default;
 	
	// PLAY
	void start(int idx);
 	GAME_STATE inputPlayer(MOVE move);	// call everytime the user want to move the player
 	
	// GAME STATE
 	bool win() const { return this->board.win(); }
 	bool loose() const { return this->board.loose(); }	// blocked box
 	bool looseNoMoreStep() const { return this->step_limit <= this->board.getPlayer()->getSteps(); }

	// MOVE
 	void canMovePlayerTo(std::vector<MOVE>& moves, Point pos) const ;	// if can move, fill the list with movements
 	void movePlayer(std::vector<MOVE>& moves);	// move player for each move in list

	// FILES
	void save(int limit) { this->levels.saveBoard(board, limit); this->start(this->current_idx); }	// save the edited level to new JSON level file
	void resetBestScore() { this->best_score=0; this->levels.updateBestScore(this->current_idx, 0); }

	// GETTERS
	const std::string& getStatus() const { return this->status; }
	int getBestScore() const { return this->best_score; }
	int getStepLimit() const { return this->step_limit; }
	int getCurrentIdx() const { return this->current_idx; }
	int getSelectIdx() const { return this->select_idx; }

	// BOARD GETTERS
 	Player* getPlayer() { return this->board.getPlayer(); }
	Matrix<std::unique_ptr<Cell>>* getMap() { return this->board.getMap(); } 
	std::vector<Box>* getBoxes() { return this->board.getBoxes(); }
	Board* getBoard() { return &this->board; }

	// SETTERS
	void setSelectIdx(int inc) { this->select_idx = mod(this->select_idx+inc, this->levels.getSize()); }
	void setStatus(int code);

};

#endif