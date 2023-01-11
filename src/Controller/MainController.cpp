#include "../include.hpp"
#include "MainController.hpp"


void MainController::keyPressed(int key_code, GAME_STATE &state) {

	switch(state) {

		case GAME_STATE::WELCOME:
			state = GAME_STATE::INGAME;
			break;

		case GAME_STATE::INGAME:
			game_board.keyPressed(key_code);
			menu.keyPressed(key_code);
			state = game_board.getNewState();
			break;

		case GAME_STATE::ENDGAME:
			menu.keyPressed(key_code);
			state = menu.getNewState();
			break;

		case GAME_STATE::EDITOR:
			editor.keyPressed(key_code);
			break;
		
	}
}


void MainController::mouseClick(Point mouse_loc, GAME_STATE &state) {

	switch(state) {

		case GAME_STATE::WELCOME:
			state = GAME_STATE::INGAME;
			break;

		case GAME_STATE::INGAME:
			menu.mouseClick(mouse_loc);
			game_board.mouseClick(mouse_loc);
			state = game_board.getNewState();
			if (menu.getNewState() == GAME_STATE::EDITOR) { state = GAME_STATE::EDITOR; }
			break;

		case GAME_STATE::ENDGAME:
			menu.mouseClick(mouse_loc);
			state = menu.getNewState();
			break;
			
		case GAME_STATE::EDITOR:
			editor_board.mouseClick(mouse_loc);
			editor.mouseClick(mouse_loc);
			if (editor.getNewState() == GAME_STATE::INGAME) { state = GAME_STATE::INGAME; }
			break;
	}
}
