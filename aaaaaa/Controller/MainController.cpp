#include <iostream>

#include "../configs.hpp"
#include "MainController.hpp"


void MainController::keyPressed(int key_code, GAME_STATE state) {
	std::cout << key_code << std::endl;
	std::cout << (int)state << std::endl;
}


void MainController::mouseClick(Point mouse_loc, GAME_STATE state) {
	std::cout << mouse_loc.x << "/" << mouse_loc.y << std::endl;
	std::cout << (int)state << std::endl;
}