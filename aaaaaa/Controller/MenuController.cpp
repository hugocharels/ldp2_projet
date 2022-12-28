#include <iostream>

#include "../configs.hpp"
#include "MenuController.hpp"


void MenuController::keyPressed(int key_code) {
	std::cout << key_code << std::endl;
}


void MenuController::mouseClick(Point mouse_loc) {
	std::cout << mouse_loc.x << "/" << mouse_loc.y << std::endl;    
}
