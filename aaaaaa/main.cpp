#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

#include "Game.hpp"


int main(int argc, char *argv[]) {
	Game().start(argc, argv);
	return Fl::run();
}
