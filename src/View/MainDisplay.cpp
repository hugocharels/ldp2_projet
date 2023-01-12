#include "../include.hpp"
#include "BoardDisplay.hpp"
#include "EditorDisplay.hpp"
#include "MenuDisplay.hpp"
#include "MainDisplay.hpp"


void MainDisplay::draw(GAME_STATE state) {

	switch(state) {

		case GAME_STATE::WELCOME:
			menu.drawWelcome();
			break;

		case GAME_STATE::INGAME:
		case GAME_STATE::ENDGAME:
			board.draw();
			menu.draw();
			break;

		case GAME_STATE::EDITOR:
			board.draw();
			editor.draw();
			break;
			
	}
}
