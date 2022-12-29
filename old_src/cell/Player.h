#ifndef _PLAYER_H
#define _PLAYER_H

#include "MoveableCell.h"
#include "../configs.h"


class Player: public MoveableCell {

	int steps=0;

public:

	Player(Point pos=Point{0, 0}): Cell(PLAYER), MoveableCell(PLAYER, pos) {}

	~Player()=default;

	void tp(Point pos) {this->position = pos;}

	void move(MOVE movement) override {
		MoveableCell::move(movement);
		this->steps++;
	}

	int getSteps() const { return steps; }
	
};


#endif