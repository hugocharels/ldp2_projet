#ifndef _TARGET_HPP
#define _TARGET_HPP

#include "ColorCell.hpp"
#include "../../configs.hpp"


class Target: public ColorCell {

public:

	Target(COLOR color=COLOR::NONE): Cell(TARGET), ColorCell(TARGET, color) {}

	~Target()=default;

	void operator=(Target &other) { this->setColor(other.getColor()); }

	virtual bool walkable() override { return true; }

};


#endif