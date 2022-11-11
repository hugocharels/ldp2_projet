#ifndef _PLAYER_H
#define _PLAYER_H

#include "configs.h"


class Player:public Moveable {

	int step_counter=0;

public:

	Player(Point pos):Moveable(pos);

	~Player()=default;

	void move(Point &pos) override {
		this->step_counter++;
		Moveable::move(pos);
	}

	int stepCounter() const { return step_counter; }

};

#endif