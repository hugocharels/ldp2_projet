#include <iostream>

#include "BoardController.hpp"


void BoardController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void BoardController::mouseClick(Point mouse_loc) {
	std::cout << mouse_loc.x << "/" << mouse_loc.y << std::endl;    
}
