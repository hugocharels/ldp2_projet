#ifndef _BOX_H
#define _BOX_H

#include "MoveableCell.h"
#include "ColorCell.h"
#include "../configs.h"


class Box: public Moveable, public ColorCell {

	bool on_target=false;

public:

	Box(Point pos, COLOR color=COLOR::NONE): ColorCell(color), Moveable(pos) {}

	~Box()=default;

	bool onTarget() const { return on_target; }

	void setTarget(bool x) { this->on_target = x; }

};


#endif