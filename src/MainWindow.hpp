#ifndef _MAIN_WINDOW_HPP
#define _MAIN_WINDOW_HPP

#include "include.hpp"
#include "View/MainDisplay.hpp"
#include "Controller/MainController.hpp"


class MainWindow : public Fl_Double_Window {
	
    MainDisplay* display;
    MainController* controller;

	int time_in_welcome_remaining = REFRESH_PER_SECOND * TIME_IN_WELCOME;
	GAME_STATE state = GAME_STATE::WELCOME;

public:

	MainWindow(MainDisplay* display, MainController* controller):
            Fl_Double_Window(500, 200, WINDOW_WIDTH, WINDOW_HEIGHT, "Sokoban"), 
            display{display}, controller{controller} {
		Fl::add_timeout(1.0 / REFRESH_PER_SECOND, Timer_CB, this);
		color(fl_rgb_color(112,146,191));
	}

	void draw() {
		Fl_Window::draw();
		if (state == GAME_STATE::WELCOME) {
			if (this->time_in_welcome_remaining <= 0) { state = GAME_STATE::INGAME; }
			else { this->time_in_welcome_remaining--; }
		}
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
		Fl::repeat_timeout(1.0 / REFRESH_PER_SECOND, Timer_CB, userdata);
	}

};

#endif