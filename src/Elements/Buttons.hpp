#include "../include.hpp"
#include "MenuElement.hpp"


//GAME MENU
const std::array<std::shared_ptr<TextRectangle>, 5> MENU_BUTTONS{
		std::make_shared<TextRectangle>(Point{730,90}, 15, 15, "↺"),
		std::make_shared<TextRectangle>(Point{580,400}, 15, 15, "<"),
		std::make_shared<TextRectangle>(Point{720,400}, 15, 15, ">"),
		std::make_shared<TextRectangle>(Point{650,440}, 125, 35, "New game"),
		std::make_shared<TextRectangle>(Point{650,480}, 125, 35, "Edit level")
};

//EDITOR
const std::array<std::shared_ptr<TextRectangle>, 9> EDIT_ELEM_BUTTONS{
		std::make_shared<TextRectangle>(Point{620,100}, 15, 15, "<"),		//box
		std::make_shared<TextRectangle>(Point{690,100}, 15, 15, ">"),

		std::make_shared<TextRectangle>(Point{620,225}, 15, 15, "<"),		//target
		std::make_shared<TextRectangle>(Point{690,225}, 15, 15, ">"),

		std::make_shared<TextRectangle>(Point{770,225}, 15, 15, "<"),		//tp
		std::make_shared<TextRectangle>(Point{850,225}, 15, 15, ">"),

		std::make_shared<TextRectangle>(Point{785,440}, 15, 15, "<"),		//step limit
		std::make_shared<TextRectangle>(Point{835,440}, 15, 15, ">"),

		std::make_shared<TextRectangle>(Point{740,490}, 125, 35, "Finish"),
};

const std::array<std::shared_ptr<TextRectangle>, 6> SELECT_ELEM_BUTTONS{
		std::make_shared<TextRectangle>(Point{655,150}, 30, 15, "-"),		//box
		std::make_shared<TextRectangle>(Point{810,150}, 30, 15, "-"),		//player
		std::make_shared<TextRectangle>(Point{655,260}, 30, 15, "-"),		//target
		std::make_shared<TextRectangle>(Point{810,260}, 30, 15, "-"),		//tp
		std::make_shared<TextRectangle>(Point{655,390}, 30, 15, "-"),		//wall
		std::make_shared<TextRectangle>(Point{810,390}, 30, 15, "-"),		//empty

};

