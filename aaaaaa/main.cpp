#include <FL/Fl.H>

#include "Game.hpp"


int main(int argc, char *argv[]) {
	Game().start(argc, argv);
	return Fl::run();
}
