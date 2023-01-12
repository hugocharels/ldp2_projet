#include "../include.hpp"
#include "MenuDisplay.hpp"
#include "../Elements/Buttons.hpp"
#include "../images.hpp"


// PUBLIC DRAW

void MenuDisplay::draw() {
    this->drawButtons();
    this->drawBestScore();
    this->drawStepCounter();
    this->drawLimitStep();
    this->drawLevelSelector();

}

void MenuDisplay::drawWelcome() {
	Fl_Image* image_ptr = Fl_PNG_Image(&WELCOME[0]).copy(WINDOW_WIDTH, WINDOW_HEIGHT);
	image_ptr->draw(0, 0);
	delete image_ptr;
}


// PRIVATE DRAW

void MenuDisplay::drawButtons() {
    for (auto& button : MENU_BUTTONS) {
        button->print();
    }
}

void MenuDisplay::drawBestScore() {
    Text{"Best score:", Point{725, 60}, TEXT_SIZE}.print();
    const std::string score = (this->model->getBestScore() == 0) ? "No best score" : std::to_string(this->model->getBestScore());
	TextRectangle{Point{725,90}, 125, 35, score}.print();
}

void MenuDisplay::drawStepCounter() {
	Text{"Steps:", Point{725,160}, TEXT_SIZE}.print();
	const int count = this->model->getPlayer()->getSteps();
    TextRectangle{Point{725,190}, 125, 35, std::to_string(count)}.print();
}

void MenuDisplay::drawLimitStep() {
	Text{"Left steps:", Point{725,260}, TEXT_SIZE}.print();
	if (this->model->getStepLimit() == 0){
		TextRectangle{Point{725,290}, 125, 35, "No limit"}.print();
	} else {
		const int step_remaining = this->model->getStepLimit() - this->model->getPlayer()->getSteps();
		TextRectangle{Point{725,290}, 125, 35, std::to_string(step_remaining)}.print();
	}
}

void MenuDisplay::drawLevelSelector() {
	Text{"Select level:", Point{735,370}, TEXT_SIZE}.print();
	TextRectangle{Point{725,400}, 110, 35, "Level " + std::to_string(this->model->getSelectIdx())}.print();
}
