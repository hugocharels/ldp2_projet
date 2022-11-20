#ifndef _TELEPORTER_H
#define _TELEPORTER_H

#include "ColorCell.h"
#include "../configs.h"


class Teleporter: public ColorCell {

	Point destination;

public:

	Teleporter(Point dest, COLOR color=COLOR::NONE): ColorCell(color), destination{dest} {}

	~Teleporter()=default;

	Point getTpPos() const { return destination; }

};


#endif