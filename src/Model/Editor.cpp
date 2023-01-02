#include "../include.hpp"
#include "Editor.hpp"


void Editor::selectElem(CELL cell) { 
    if (cell == selected) {
        this->is_selected = not this->is_selected;
    } else {
        this->selected = cell;
        this->is_selected = true;
    }
}


void Editor::placeElem(Point pos) {
    if (not is_selected) { return; }

    std::cout << (char)selected << " : " << pos.x << "/" << pos.y << std::endl;

}