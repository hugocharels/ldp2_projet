#include "../include.hpp"
#include "EditorController.hpp"


void EditorController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void EditorController::mouseClick(Point mouse_loc) {
	std::cout << mouse_loc.x << "/" << mouse_loc.y << std::endl;    
}
