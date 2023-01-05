#include "../include.hpp"
#include "EditorDisplay.hpp"
#include "../Elements/Buttons.hpp"
#include "../Elements/MenuElement.hpp"
#include "../images.hpp"


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
    Fl_Image* image_ptr;
    image_ptr = Fl_PNG_Image(&(box_list[model->getBoxIdx()])[0]).copy(cellSize, cellSize);
    image_ptr->draw(630, 80);
    delete image_ptr;
}

void EditorDisplay::drawPlayer(){
    Text{"Player", Point{810, 60}, textSize}.print();
    Fl_Image* image_ptr = Fl_PNG_Image(&IM_PLAYER[0]).copy(cellSize, cellSize);
    image_ptr->draw(785, 70);
    delete image_ptr;
}

void EditorDisplay::drawTarget(){
    Text{"Target", Point{660, 195}, textSize}.print();
    Fl_Image* image_ptr;
    image_ptr = Fl_PNG_Image(&(target_list[model->getTargetIdx()])[0]).copy(cellSize, cellSize);
    image_ptr->draw(630, 200);
    delete image_ptr;
}

void EditorDisplay::drawTeleporter(){
    Text{"Teleporter", Point{810, 195}, textSize}.print();
    Fl_Image* image_ptr;
    image_ptr = Fl_PNG_Image(&(tp_list[model->getTeleporterIdx()])[0]).copy(cellSize, cellSize);
    image_ptr->draw(785, 200);
    delete image_ptr;
}

void EditorDisplay::drawWall(){
    Text{"Wall", Point{655, 300}, textSize}.print();
    Fl_Image* image_ptr = Fl_PNG_Image(&IM_WALL[0]).copy(cellSize, cellSize);
    image_ptr->draw(630, 320);
    delete image_ptr;
}

void EditorDisplay::drawEmpty(){
    Text{"Empty", Point{810, 300}, textSize}.print();
    Fl_Image* image_ptr = Fl_PNG_Image(&FLOOR[0]).copy(cellSize, cellSize);
    image_ptr->draw(785,320 );
    delete image_ptr;
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