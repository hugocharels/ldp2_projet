#include "../include.hpp"
#include "EditorBoardController.hpp"


void EditorBoardController::keyPressed(int key_code) {
    std::cout << key_code << std::endl;
}


void EditorBoardController::mouseClick(Point mouse_loc) {
    
    std::cout << mouse_loc.x << "/" << mouse_loc.y << std::endl;

}
