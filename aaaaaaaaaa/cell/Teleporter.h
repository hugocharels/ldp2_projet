#ifndef _TELEPORTER_H
#define _TELEPORTER_H

#include "ColorCell.h"
#include "../configs.h"


class Teleporter: public ColorCell {

	Point destination;

public:

	Teleporter(Point dest=Point{0,0}, COLOR color=COLOR::NONE): ColorCell(TP, color), destination{dest} {}

	~Teleporter()=default;

	Point getTpPos() const { return destination; }

	void setDestination(Point pos) { this->destination=pos; }

};


#endif