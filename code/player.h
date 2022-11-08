#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "configs.h"


class Player {

	Point position;

public:

	Player()=default;

	~Player()=default;

	void move(Point &pos) {
		this->position.x = pos.x;
		this->position.y = pos.y;
	}

}

#endif