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

	void move(MOVE movement) {
		if (movement == UP) {position.x--;}
		else if (movement == DOWN) {position.x++;}
		else if (movement == LEFT) {position.y--;}
		else if (movement == RIGHT) {position.y++;}
		this->step_counter++;
	}

	int stepCounter() const { return step_counter; }

	Point getPos() const { return position; }

};


// --------- Box -------------- //

class Box:public Moveable {

	bool on_target=false;

public:

	Box(Point pos):Moveable(pos) {}

	~Box()=default;

	bool onTarget() const { return on_target; }

	void setTarget(bool x) { this->on_target = x; }

};


// --------- Player ----------- //

class Player:public Moveable {

public:

	Player(Point pos=Point{0, 0}):Moveable(pos) {}
	~Player()=default;

};


#endif