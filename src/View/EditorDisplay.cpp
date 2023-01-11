#include "../include.hpp"
#include "../Elements/Buttons.hpp"
#include "../Elements/MenuElement.hpp"
#include "../images.hpp"
#include "DrawCell.hpp"
#include "EditorDisplay.hpp"


void EditorDisplay::draw() {
	this->drawButtons();
	this->drawBox();
	this->drawTarget();
	this->drawTeleporter();
	this->drawPlayer();
	this->drawWall();
	this->drawEmpty();
	this->drawStepLimit();
}

void EditorDisplay::drawButtons(){ //la meme que dans menu display sauf button
	for (auto& button : EDIT_ELEM_BUTTONS) {
		button->print();
	}

	if (model->isSelected()) {
		SELECT_ELEM_BUTTONS[model->getElemIdx()]->setFillColor(FL_RED);   
	}
	for (auto& button : SELECT_ELEM_BUTTONS) {
		button->print();
	}
	if (model->isSelected()) {
		SELECT_ELEM_BUTTONS[model->getElemIdx()]->setFillColor(FL_WHITE);   
	}
}

void EditorDisplay::drawBox(){
	Text{"Box", Point{655, 60}, textSize}.print();
	DrawCell{Point{630, 80}, box_list[model->getBoxIdx()]};
}

void EditorDisplay::drawPlayer(){
	Text{"Player", Point{810, 60}, textSize}.print();
	DrawCell{Point{785, 70}, IM_PLAYER};
}

void EditorDisplay::drawTarget(){
	Text{"Target", Point{660, 195}, textSize}.print();
	DrawCell{Point{630, 200}, target_list[model->getTargetIdx()]};
}

void EditorDisplay::drawTeleporter(){
	Text{"Teleporter", Point{810, 195}, textSize}.print();
	DrawCell{Point{785, 200}, tp_list[model->getTeleporterIdx()]};
}

void EditorDisplay::drawWall(){
	Text{"Wall", Point{655, 300}, textSize}.print();
	DrawCell{Point{630, 320}, IM_WALL};
}

void EditorDisplay::drawEmpty(){
	Text{"Empty", Point{810, 300}, textSize}.print();
	DrawCell{Point{785, 320}, FLOOR};
}

void EditorDisplay::drawStepLimit(){
	Text{"Step limit", Point{700, 440}, textSize}.print();
	if (model->getStepLimit()==0) {
		Text{"-", Point{810, 440}, textSize}.print();
	}
	else {
		Text{std::to_string(model->getStepLimit()), Point{810, 440}, textSize}.print();
	}
}