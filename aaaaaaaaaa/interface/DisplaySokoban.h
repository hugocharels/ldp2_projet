#ifndef _DISPLAY_SOKOBAN_H
#define _DISPLAY_SOKOBAN_H

#include<vector>

#include "../game/Sokoban.h"
#include "../cell/include.h"
#include "../configs.h"


class DisplaySokoban {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;
	vector<shared_ptr<Printable>> menu_elem;

	Point modelPosToDisplayPos(Point model_pos) { return Point{cellSize+(cellSize*model_pos.y), cellSize+(cellSize*model_pos.x)}; }
	
	void drawMap();
	void drawAFloor(Point display_pos);
	void drawAWall(Point display_pos);
	void drawAPlayer(Point display_pos);
	void drawATp(Point display_pos, COLOR color);
	void drawATarget(Point display_pos, COLOR color);
	void drawABox(Point display_pos, COLOR color);
	void drawACell(Point display_pos, Cell* cell);

	//void drawMenu();
	//void drawBestScore();
	//void drawStepCounter();
	//void drawLimitStep();


public:

	explicit DisplaySokoban(Fl_Window* fltkWindow, Sokoban* sokoban):fltkWindow{fltkWindow},sokoban{sokoban} {}

	~DisplaySokoban()=default;

	void draw(); //draw toute les cell pour le moment

};


#endif