#ifndef _DISPLAY_SOKOBAN_H
#define _DISPLAY_SOKOBAN_H

#include "../game/Sokoban.h"
#include "../cell/include.h"
#include "../configs.h"


class DisplaySokoban {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;

	Point modelPosToDisplayPos(Point model_pos) { return Point{cellSize+(cellSize*model_pos.x), cellSize+(cellSize*model_pos.y)}; }
	void drawACell(Point display_pos, Cell* cell); 

public:

	explicit DisplaySokoban(Fl_Window* fltkWindow, Sokoban* sokoban):fltkWindow{fltkWindow},sokoban{sokoban} {}

	~DisplaySokoban()=default;

	void draw(); //draw toute les cell pour le moment

};


#endif