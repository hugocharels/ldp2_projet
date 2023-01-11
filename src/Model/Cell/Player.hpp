#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "MoveableCell.hpp"
#include "../../configs.hpp"


class Player: public MoveableCell {

	int steps=0;

public:

	Player(Point pos=Point{0, 0}): Cell(CELL::PLAYER), MoveableCell(CELL::PLAYER, pos) {}
	~Player()=default;

	void tp(Point pos) { this->position = pos; }

	void move(MOVE movement) override {
		MoveableCell::move(movement);
		this->steps++;
	}

	// GETTER
	int getSteps() const { return steps; }
	
};

#endif