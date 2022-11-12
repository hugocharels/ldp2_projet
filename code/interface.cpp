#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

#include <iostream>
#include <math.h>
#include <time.h>

#include "interface.h"
#include "configs.h"



int main(int argc, char *argv[]) {
	MainWindow window;
	window.show(argc, argv);
	return Fl::run();
}
