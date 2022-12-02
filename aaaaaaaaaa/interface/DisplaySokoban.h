#ifndef _DISPLAY_SOKOBAN_H
#define _DISPLAY_SOKOBAN_H

#include "../game/Sokoban.h"
#include "../cell/include.h"
#include "../configs.h"


class DisplaySokoban {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;

	Point modelPosToDisplayPos(Point model_pos) { return Point{cellSize+(cellSize*model_pos.y), cellSize+(cellSize*model_pos.x)}; }
	
	void inline drawAFloor(Point display_pos);
	void inline drawAWall(Point display_pos);
	void inline drawAPlayer(Point display_pos);
	void inline drawATp(Point display_pos, COLOR color);
	void inline drawATarget(Point display_pos, COLOR color);
	void inline drawABox(Point display_pos, COLOR color);

	void inline drawACell(Point display_pos, Cell* cell); 

public:

	explicit DisplaySokoban(Fl_Window* fltkWindow, Sokoban* sokoban):fltkWindow{fltkWindow},sokoban{sokoban} {}

	~DisplaySokoban()=default;

	void draw(); //draw toute les cell pour le moment

};


#endif