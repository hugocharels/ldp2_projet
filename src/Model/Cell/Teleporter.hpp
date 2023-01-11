#ifndef _TELEPORTER_HPP
#define _TELEPORTER_HPP

#include "ColorCell.hpp"
#include "../../configs.hpp"


class Teleporter: public ColorCell {

	Point destination;

public:

	Teleporter(Point dest, COLOR color=COLOR::NONE): Cell(CELL::TP), ColorCell(CELL::TP, color), destination{dest} {}
	Teleporter(COLOR color=COLOR::NONE): Cell(CELL::TP), ColorCell(CELL::TP, color) {}
	~Teleporter()=default;

	virtual bool walkable() override { return true; }
	
	// GETTER
	Point getTpPos() const { return destination; }

	// SETTER
	void setDestination(Point pos) { this->destination=pos; }

};

#endif