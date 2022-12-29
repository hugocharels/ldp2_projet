#include <FL/Fl.H>

#include "interface/MainWindow.h"
#include "game/Sokoban.h"


int main(int argc, char *argv[]) {
	Sokoban sokoban;
	MainWindow window{&sokoban};
	window.show(argc, argv);
	return Fl::run();
}
