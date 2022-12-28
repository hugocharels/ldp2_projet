#ifndef _MAIN_WINDOW_HPP
#define _MAIN_WINDOW_HPP

#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

#include "configs.hpp"
#include "View/MainDisplay.hpp"
#include "Controller/MainController.hpp"


class MainWindow : public Fl_Double_Window {
	
    MainDisplay* display;
    MainController* controller;

	GAME_STATE state = GAME_STATE::PLAY;

public:

	MainWindow(MainDisplay* display, MainController* controller):
            Fl_Double_Window(500, 200, windowWidth, windowHeight, "Sokoban"), 
            display{display}, controller{controller} {
		Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
	}

	void draw() {
		Fl_Window::draw();
		display->draw(state);
	}

	int handle(int event) override {
		switch (event) {
			case FL_PUSH:
				controller->mouseClick(Point{Fl::event_x(), Fl::event_y()}, state);
				return 1;
			case FL_KEYDOWN:
				controller->keyPressed(Fl::event_key(), state);
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