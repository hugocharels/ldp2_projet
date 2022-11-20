#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

#include "sokoban.h"
#include "configs.h"


constexpr int    windowWidth      = 500;
constexpr int    windowHeight     = 500;
constexpr double refreshPerSecond = 60;


//-------------CONTROLLER----------------------
class ControllerSokoban {
	Fl_Window* fltkWindow;
	Sokoban* sokoban;
public:
	ControllerSokoban(Fl_Window* fltkWindow, Sokoban* sokoban) :fltkWindow{fltkWindow},sokoban{sokoban} {}

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
		this->sokoban->inputPlayer(move);
	}

	void mouseClick(Point mouse_loc) {
		this->sokoban->restart();
		std::cout << mouse_loc.x << " / " << mouse_loc.y << std::endl;
	}
};



//---------------VIEW---------------
class Canvas {

	Fl_Window* fltkWindow;
	Sokoban* sokoban;

public:

	explicit Canvas(Fl_Window* fltkWindow, Sokoban* sokoban):fltkWindow{fltkWindow},sokoban{sokoban} {}

	~Canvas()=default;

	void draw() {}

};


//---------------MAIN WINDOWS---------------
class MainWindow : public Fl_Window {
	Sokoban* sokoban_model;
	Canvas canvas{this, sokoban_model};
	ControllerSokoban controller{this, sokoban_model};

public:

	MainWindow(Sokoban* sokoban):Fl_Window(500, 500, windowWidth, windowHeight, "Sokoban"), sokoban_model{sokoban} {
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