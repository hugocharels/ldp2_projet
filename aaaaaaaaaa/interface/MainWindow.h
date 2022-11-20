#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

#include "../game/Sokoban.h"
#include "../configs.h"


class MainWindow : public Fl_Window {
	
	Sokoban* sokoban_model;
	
	DisplaySokoban display{this, sokoban_model};
	
	ControllerSokoban controller{this, sokoban_model};

public:

	MainWindow(Sokoban* sokoban):Fl_Window(500, 500, windowWidth, windowHeight, "Sokoban"), sokoban_model{sokoban} {
		Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
		resizable(this);
	}

	void draw() {
		Fl_Window::draw();
		//display.draw();
	}

	int handle(int event) override {
		switch (event) {
			case FL_PUSH:
				controller.mouseClick(Point{Fl::event_x(), Fl::event_y()});
				return 1;
			case FL_KEYDOWN:
				controller.keyPressed(Fl::event_key());
				return 1;
			default:
				return 0;
		} return 0;
	}

	static void Timer_CB(void *userdata) {
		MainWindow *o = static_cast<MainWindow *>(userdata);
		o->redraw();
		Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
	}

};


#endif