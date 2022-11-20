#ifndef _PLAYER_H
#define _PLAYER_H

#include "MoveableCell.h"
#include "../configs.h"


class Player: public MoveableCell {

public:

	Player(Point pos): MoveableCell(pos) {}

	~Player()=default;

};


#endif