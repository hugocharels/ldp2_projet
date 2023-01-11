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
	void loadFiles();

	// BOARD
	void createBoard(int idx, Board &board, int &best_score, int &step_limit) const;
	void saveBoard(Board &board, int step_limit);

	// UPDATE
	void updateBestScore(int idx, int new_best_score);

	// GETTERS
	const std::string& getFile(int idx) const { return this->files[idx]; }
	int getSize() const { return this->files.size(); }

};

#endif