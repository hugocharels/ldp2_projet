#ifndef _EDITOR_DISPLAY_HPP
#define _EDITOR_DISPLAY_HPP

#include "../include.hpp"
#include "../Model/Editor.hpp"
#include "AbstractDisplay.hpp"


class EditorDisplay: public AbstractDisplay {
	Editor* model;
	int textSize=20;

	void drawButtons();
	void drawBox();
	void drawTarget();
	void drawTeleporter();
	void drawPlayer();
	void drawWall();
	void drawEmpty();

public:

	void draw() override;

	void setModel(Editor* m) { this->model = m; }

};


#endif