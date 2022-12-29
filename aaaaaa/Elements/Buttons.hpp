#include "../include.hpp"
#include "MenuElement.hpp"


//GAME MENU
const std::array<std::shared_ptr<TextRectangle>, 5> MENU_BUTTONS{
		std::make_shared<TextRectangle>(Point{730,90}, 15, 15, "↺"),
		std::make_shared<TextRectangle>(Point{580,400}, 15, 15, "<"),
		std::make_shared<TextRectangle>(Point{720,400}, 15, 15, ">"),
		std::make_shared<TextRectangle>(Point{650,440}, 110, 35, "Load"),
		std::make_shared<TextRectangle>(Point{650,480}, 110, 35, "Create")
};
