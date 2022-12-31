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
const std::array<std::shared_ptr<TextRectangle>, 7> EDIT_ELEM_BUTTONS{
		std::make_shared<TextRectangle>(Point{620,100}, 15, 15, "<"),		//box
		std::make_shared<TextRectangle>(Point{690,100}, 15, 15, ">"),

		std::make_shared<TextRectangle>(Point{770,90}, 15, 15, "<"),		//target
		std::make_shared<TextRectangle>(Point{850,90}, 15, 15, ">"),

		std::make_shared<TextRectangle>(Point{620,210}, 15, 15, "<"),		//tp 
		std::make_shared<TextRectangle>(Point{690,210}, 15, 15, ">"),

		std::make_shared<TextRectangle>(Point{740,440}, 125, 35, "Finish"),
};

/*const std::array<std::shared_ptr<Fl_Image*>, 7> EDIT_BOX_BUTTONS{

};

const std::array<std::shared_ptr<Fl_Image*>, 7> EDIT_TARGET_BUTTONS{

};

const std::array<std::shared_ptr<Fl_Image*>, 3> EDIT_TELEPORTER_BUTTONS{

};

const std::array<std::shared_ptr<Fl_Image*>, 3> EDIT_ELEM_BUTTONS{

};*/