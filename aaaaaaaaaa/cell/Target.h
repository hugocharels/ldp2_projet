#ifndef _TARGET_H
#define _TARGET_H

#include "ColorCell.h"
#include "../configs.h"


class Target: public ColorCell {

public:

	Target(COLOR color=COLOR::NONE): ColorCell(color) {}

	~Target()=default;

};


#endif