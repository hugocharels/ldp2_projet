#include "../include.hpp"
#include "MainController.hpp"


void MainController::keyPressed(int key_code, GAME_STATE &state) {

	switch(state) {

		case GAME_STATE::WELCOME:
			state = GAME_STATE::PLAY;
			break;

		case GAME_STATE::PLAY:
			board.keyPressed(key_code);
			menu.keyPressed(key_code);
			std::cout << " key board " << (int)state;
			state = board.getNewState();
			std::cout << " --> " << (int)state << std::endl;
			break;

		case GAME_STATE::WON:
		case GAME_STATE::LOST:
			menu.keyPressed(key_code);
			std::cout << " key menu " << (int)state;
			state = menu.getNewState();
			std::cout << " --> " << (int)state << std::endl;
			break;

		case GAME_STATE::EDITOR:
			editor.keyPressed(key_code);
			break;
		
	}
}


void MainController::mouseClick(Point mouse_loc, GAME_STATE &state) {

	switch(state) {

		case GAME_STATE::WELCOME:
			state = GAME_STATE::PLAY;
			break;

		case GAME_STATE::PLAY:
			menu.mouseClick(mouse_loc);
			board.mouseClick(mouse_loc);
			std::cout << " mouse board " << (int)state;
			state = board.getNewState();
			std::cout << " --> " << (int)state << std::endl;
			break;

		case GAME_STATE::WON:
		case GAME_STATE::LOST:
			menu.mouseClick(mouse_loc);
			std::cout << " mouse menu " << (int)state;
			state = menu.getNewState();
			std::cout << " --> " << (int)state << std::endl;
			break;
			
		case GAME_STATE::EDITOR:
			editor.mouseClick(mouse_loc);
			break;
	}
}
