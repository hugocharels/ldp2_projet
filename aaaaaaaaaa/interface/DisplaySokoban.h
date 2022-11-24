#ifndef _DISPLAY_SOKOBAN_H
#define _DISPLAY_SOKOBAN_H

#include "MainWindow.h"


class DisplaySokoban {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;

	Point modelPosToDisplayPos(Point model_pos) { return Point{cellSize+(cellSize*model_pos.x), cellSize+(cellSize*model_pos.y)}; }
	void drawACell(Point display_pos, CELL c_type); 

public:

	explicit DisplaySokoban(Fl_Window* fltkWindow, Sokoban* sokoban):fltkWindow{fltkWindow},sokoban{sokoban} {}

	~DisplaySokoban()=default;

	void draw(); //draw toute les cell pour le moment

};


#endif