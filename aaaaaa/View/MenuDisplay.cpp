#include "../include.hpp"
#include "MenuDisplay.hpp"
#include "../Elements/Buttons.hpp"


void MenuDisplay::draw() {
    this->drawButtons();
}

void MenuDisplay::drawButtons() {
    for (auto& button : MENU_BUTTONS) {
        button->print();
    }
}
