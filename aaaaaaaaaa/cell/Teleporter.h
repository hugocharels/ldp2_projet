#ifndef _TELEPORTER_H
#define _TELEPORTER_H

#include "ColorCell.h"
#include "../configs.h"


class Teleporter: public ColorCell {

	Point destination;

public:

	Teleporter(Point dest, COLOR color=COLOR::NONE): Cell(TP), ColorCell(TP, color), destination{dest} {}
	Teleporter(COLOR color=COLOR::NONE): Cell(TP), ColorCell(TP, color) {}

	~Teleporter()=default;

	Point getTpPos() const { return destination; }

	void setDestination(Point pos) { this->destination=pos; }

	virtual bool walkable() override { return true; }
	
};


#endif