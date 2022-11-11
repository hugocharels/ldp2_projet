#ifndef _MOVEABLE_H
#define _MOVEABLE_H

#include "configs.h"


// --------- Moveable --------- //

class Moveable {

	Point position;
	int step_counter=0;

public:

	Moveable(Point pos):position{pos} {}
	~Moveable()=default;

	void move(Point &pos) {
		this->position.x = pos.x;
		this->position.y = pos.y;
		this->step_counter++;
	}

	int stepCounter() const { return step_counter; }

	Point getPos() const { return position; }

};


// --------- Box -------------- //

class Box:public Moveable {

	bool on_target=false;

public:

	Box(Point pos):Moveable(pos);

	~Box()=default;

	bool onTarget() const { return on_target; }

	void setOnTarget(bool x) { this->on_target = x; }

};


// --------- Player ----------- //

class Player:public Moveable {

public:

	Player(Point pos):Moveable(pos);

	~Player()=default;

};


#endif