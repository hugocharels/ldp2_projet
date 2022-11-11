#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "configs.h"


class Player {

	Point position;
	int step_counter=0;

public:

	Player()=default;

	~Player()=default;

	void move(Point &pos) {
		this->step_counter++;
		this->position.x = pos.x;
		this->position.y = pos.y;
	}

}

#endif