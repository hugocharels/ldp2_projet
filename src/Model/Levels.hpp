#ifndef _LEVELS_HPP
#define _LEVELS_HPP

#include "../include.hpp"
#include "Board.hpp"


class Levels {

	std::vector<std::string> files;

public:

	Levels() { this->loadFiles(); }
	~Levels()=default;

	// FILES
	void loadFiles();	// search in level directory all levels

	// BOARD
	void createBoard(int idx, Board &board, int &best_score, int &step_limit) const;	// read JSON level file and load the board
	void saveBoard(Board &board, int step_limit);	// create a new level JSON file and save the board in it

	// UPDATE
	void updateBestScore(int idx, int new_best_score);	// write the new bestscore in the level JSON file

	// GETTERS
	const std::string& getFile(int idx) const { return this->files[idx]; }
	int getSize() const { return this->files.size(); }

};

#endif