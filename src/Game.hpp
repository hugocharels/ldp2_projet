#ifndef _GAME_HPP
#define _GAME_HPP

#include "include.hpp"
#include "Model/Sokoban.hpp"
#include "View/MainDisplay.hpp"
#include "Controller/MainController.hpp"
#include "MainWindow.hpp"


class Game {

    Sokoban model;
    MainDisplay display{&model};
    MainController controller{&model};
    MainWindow window{&display, &controller};

public:

    Game()=default;
    ~Game()=default;
    
    int start(int argc, char *argv[]) { window.color(fl_rgb_color(112,146,191)); window.show(argc, argv); return Fl::run(); }

};


#endif