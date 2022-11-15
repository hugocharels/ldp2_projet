#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

#include <Fl/Fl_PNG_Image.H>

#include <iostream>


constexpr int    windowWidth      = 500;
constexpr int    windowHeight     = 500;
constexpr double refreshPerSecond = 60;

const char* PIC = "nicepic.png";


class Canvas {

	Fl_Window* fltkWindow;
	Fl_Box* mypicturebox;
	Fl_PNG_Image* myimage;

public:

	explicit Canvas(Fl_Window* fltkWindow):fltkWindow{fltkWindow},myimage{new Fl_PNG_Image(PIC)} {
		mypicturebox = new Fl_Box(100, 100, 250, 250);
		mypicturebox->image(myimage);
	}

	~Canvas()=default;

	void draw() {
		mypicturebox->redraw();
	}

	void mouseClick(int x, int y) {
		std::cout << x << " / " << y << std::endl;
	}

	void keyPressed(int key_code) {
		std::cout << key_code << std::endl;
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
				canvas.mouseClick(Fl::event_x(), Fl::event_y());
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


int main(int argc, char *argv[]) {
	MainWindow window;
	window.show(argc, argv);
	return Fl::run();
}
