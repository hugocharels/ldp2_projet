#include "../include.hpp"
#include "MainController.hpp"


void MainController::keyPressed(int key_code, GAME_STATE &state) {

	switch(state) {

		case GAME_STATE::WELCOME:
			state = GAME_STATE::PLAY;
			break;

		case GAME_STATE::PLAY:
			board.keyPressed(key_code);
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
			board.mouseClick(mouse_loc);
			menu.mouseClick(mouse_loc);
			break;

		case GAME_STATE::EDITOR:
			editor.mouseClick(mouse_loc);
			break;
	}
}