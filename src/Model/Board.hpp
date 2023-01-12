#ifndef _BOARD_HPP
#define _BOARD_HPP

#include "../include.hpp"
#include "Matrix.hpp"
#include "Cell/include.hpp"


class Board {

	Matrix<std::unique_ptr<Cell>> map;
	Player player;
	std::vector<Box> boxes;
	unsigned short target_nb;

	// CAN MOVE
	bool canPlayerMove(MOVE move) const ;
	bool canBoxMove(Box &box, MOVE move) const ;
	
	// MOVE
	void movePlayerOnTp();
	bool moveBoxOnMove(MOVE move);

	bool blockedBox(const Box &box) const ;

public:

	Board()=default;
	~Board()=default;

	// LOAD
	void loadMap(int rows, int cols, std::string &str_map);
	void loadBoxes(Json::Value &boxes_info);
	void loadPlayer(Point pos) { this->player = Player{pos}; }

	bool inMap(int x, int y) const ;
	void removeIfBox(Point pos);
	bool boxHere(Point pos) const ;

	// PLAY
	bool play(MOVE move);
	bool win() const ;
	bool loose() const ;

	// GETTERS
	Player* getPlayer() { return &player; }
	Matrix<std::unique_ptr<Cell>>* getMap() { return &map; } 
	std::vector<Box>* getBoxes() { return &boxes; }
	
	const Player* getPlayer() const { return &player; }
	const Matrix<std::unique_ptr<Cell>>* getMap() const { return &map; }

	// PRINT IN TERMINAL
	void print() const ;

};

#endif