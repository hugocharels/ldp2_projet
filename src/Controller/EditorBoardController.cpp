#include "../include.hpp"
#include "EditorBoardController.hpp"


void EditorBoardController::keyPressed(int key_code) {
    std::cout << key_code << std::endl;
}


void EditorBoardController::mouseClick(Point mouse_loc) {
    this->model->placeElem(displayPosToBoardPos(mouse_loc));
}
