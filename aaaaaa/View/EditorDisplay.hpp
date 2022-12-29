#ifndef _EDITOR_DISPLAY_HPP
#define _EDITOR_DISPLAY_HPP

#include "../include.hpp"
#include "AbstractDisplay.hpp"


class EditorDisplay: public AbstractDisplay {

public:

	void draw() override;

};


#endif