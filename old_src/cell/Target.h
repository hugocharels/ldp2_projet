#ifndef _TARGET_H
#define _TARGET_H

#include "ColorCell.h"
#include "../configs.h"


class Target: public ColorCell {

public:

	Target(COLOR color=COLOR::NONE): Cell(TARGET), ColorCell(TARGET, color) {}

	~Target()=default;

	void operator=(Target &other) { this->setColor(other.getColor()); }

	virtual bool walkable() override { return true; }

};


#endif