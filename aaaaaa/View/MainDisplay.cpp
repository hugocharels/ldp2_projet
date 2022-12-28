#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_PNG_Image.H>

#include "../configs.hpp"
#include "BoardDisplay.hpp"
#include "EditorDisplay.hpp"
#include "MenuDisplay.hpp"
#include "MainDisplay.hpp"


void MainDisplay::draw(GAME_STATE state) {

	switch(state) {

		case GAME_STATE::PLAY:
			board.draw();
			menu.draw();
			break;

		case GAME_STATE::EDITOR:
			editor.draw();
			break;
			
	}
}
