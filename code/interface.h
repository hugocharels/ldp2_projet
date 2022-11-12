#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

#include "configs.h"


constexpr int    windowWidth      = 500;
constexpr int    windowHeight     = 500;
constexpr double refreshPerSecond = 60;



class Canvas {

	Sokoban sokoban;
	Fl_Window* fltkWindow;

public:

	explicit Canvas(Fl_Window* fltkWindow):fltkWindow{fltkWindow} {}

	~Canvas()=default;

	void draw() {}

	void mouseClick(Point mouse_loc) {
		std::cout << mouse_loc.x << " / " << mouse_loc.y << std::endl;
	}

	void keyPressed(int key_code) {
		MOVE move = INVALID;
		switch(key_code) {
			case 'z':
				move = UP;
				break;
			case 's':
				move = DOWN;
				break;
			case 'q':
				move = LEFT;
				break;
			case 'd':
				move = RIGHT;
				break;
		}
		std::cout << move << std::endl;
		sokoban.inputPlayer(move);
	}

};



class MainWindow : public Fl_Window {

	Canvas canvas{this};

public:

	MainWindow():Fl_Window(500, 500, windowWidth, windowHeight, "Sokoban") {
		Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
		resizable(this);
	}

	void draw() {
		Fl_Window::draw();
		//canvas.draw();
	}

	int handle(int event) override {
		switch (event) {
			case FL_PUSH:
				canvas.mouseClick(Point{Fl::event_x(), Fl::event_y()});
				return 1;
			case FL_KEYDOWN:
				canvas.keyPressed(Fl::event_key());
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