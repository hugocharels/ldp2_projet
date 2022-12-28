#include "../include.hpp"
#include "MenuDisplay.hpp"
#include "../Elements/Buttons.hpp"


void MenuDisplay::draw() {
    this->drawButtons();
    this->drawBestScore();
    this->drawStepCounter();
    this->drawLimitStep();
    this->drawLevelSelector();
    this->drawStatus();
}

void MenuDisplay::drawButtons() {
    for (auto& button : MENU_BUTTONS) {
        button->print();
    }
}

void MenuDisplay::drawBestScore() {
    Text{"Best score:", Point{650, 60}, textSize}.print();
	TextRectangle{Point{650,90}, 125, 35, std::to_string(model->getBestScore())}.print();
}

void MenuDisplay::drawStepCounter() {
	Text{"Steps:", Point{650,160}, textSize}.print();
	int count = model->getPlayerPTR()->getSteps();
    TextRectangle{Point{650,190}, 125, 35, std::to_string(count)}.print();
}

void MenuDisplay::drawLimitStep() {
	Text{"Left steps:", Point{650,260}, textSize}.print();
	int step_remaining = model->getStepLimit() - model->getPlayerPTR()->getSteps();
	TextRectangle{Point{650,290}, 125, 35, std::to_string(step_remaining)};
}

void MenuDisplay::drawLevelSelector() {
	Text{"Select level:", Point{650,370}, textSize}.print();
	TextRectangle{Point{650,400}, 110, 35, "Level " + std::to_string(model->getSelectIdx())};
}

void MenuDisplay::drawStatus() {
	TextRectangle{Point{300,550}, 500, 35, model->getStatus()}.print();
}
