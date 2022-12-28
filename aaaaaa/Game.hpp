#ifndef _GAME_HPP
#define _GAME_HPP

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
    
    void start(int argc, char *argv[]) { window.show(argc, argv); }

};


#endif