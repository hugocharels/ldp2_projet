#include "../include.hpp"
#include "BoardDisplay.hpp"
#include "EditorDisplay.hpp"
#include "MenuDisplay.hpp"
#include "MainDisplay.hpp"


void MainDisplay::draw(GAME_STATE state) {

	switch(state) {

		case GAME_STATE::WELCOME:
			break;

		case GAME_STATE::PLAY:
			board.draw();
			menu.draw();
			break;

		case GAME_STATE::EDITOR:
			editor.draw();
			break;
			
	}
}
