#ifndef _BOX_HPP
#define _BOX_HPP

#include "MoveableCell.hpp"
#include "ColorCell.hpp"
#include "../../configs.hpp"


class Box: public MoveableCell, public ColorCell {

	bool on_target=false;

public:

	Box(Point pos, COLOR color=COLOR::NONE): Cell(BOX), MoveableCell(BOX, pos), ColorCell(BOX, color) {}
	~Box()=default;

	bool onTarget() const { return on_target; }

	// SETTER
	void setTarget(bool x) { this->on_target = x; }

};


#endif