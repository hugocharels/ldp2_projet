#ifndef _BOX_H
#define _BOH_H

#include "configs.h"


class Box:public Moveable {

	bool on_target=false;

public:

	Box(Point pos):Moveable(pos);

	~Box()=default;

	bool onTarget() const { return on_target; }

};

#endif