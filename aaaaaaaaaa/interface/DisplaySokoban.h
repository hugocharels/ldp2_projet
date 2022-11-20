#ifndef _DISPLAY_SOKOBAN_H
#define _DISPLAY_SOKOBAN_H

#include "MainWindow.h"


class DisplaySokoban {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;

public:

	explicit DisplaySokoban(Fl_Window* fltkWindow, Sokoban* sokoban):fltkWindow{fltkWindow},sokoban{sokoban} {}

	~DisplaySokoban()=default;

	void draw() {}

};


#endif