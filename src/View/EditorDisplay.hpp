#ifndef _EDITOR_DISPLAY_HPP
#define _EDITOR_DISPLAY_HPP

#include "../include.hpp"
#include "../Model/Editor.hpp"
#include "AbstractDisplay.hpp"


class EditorDisplay: public AbstractDisplay {

	const std::array<const std::string, N_BOX> box_list{NONE_BOX, RED_BOX, ORANGE_BOX, YELLOW_BOX, GREEN_BOX, BLUE_BOX, PURPLE_BOX };
	const std::array<const std::string, N_TARGET> target_list{NONE_TARGET, RED_TARGET, ORANGE_TARGET, YELLOW_TARGET, GREEN_TARGET, BLUE_TARGET, PURPLE_TARGET };
	const std::array<const std::string, N_TP> tp_list{GREEN_TP, PINK_TP, PURPLE_TP};

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