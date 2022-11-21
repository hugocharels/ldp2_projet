#ifndef _PLAYER_H
#define _PLAYER_H

#include "MoveableCell.h"
#include "../configs.h"


class Player: public MoveableCell {

public:

	Player(Point pos=Point{0, 0}): MoveableCell(pos) {}

	~Player()=default;

};


#endif