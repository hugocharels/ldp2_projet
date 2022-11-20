#include <FL/Fl.H>

#include "display/Display.h"


int main(int argc, char *argv[]) {
	MainWindow window;
	window.show(argc, argv);
	return Fl::run();
}
