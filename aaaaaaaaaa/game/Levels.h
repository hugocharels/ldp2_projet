#include <vector>
#include <string>

#include "Board.h"


class Levels {

	std::vector<const std::string> files;

public:

	Levels() { this->loadFiles(); }
	~Levels()=default;

	void loadFiles();

	void createBoard(int idx, Board &board, int &best_score, int &step_limit) const;

	void saveBoard(Board &board);

	void updateBestScore(int idx, int new_best_score);

	const std::string& getFile(int idx) const { return this->files[idx]; }

};
