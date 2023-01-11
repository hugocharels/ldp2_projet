CXX = g++
CXXFLAGS += -std='c++2a' -Werror -Wall -Wextra -pedantic
CXXLIBS += -lfltk -lfltk_images -ljsoncpp

main: main.cpp
	make View -B
	make Controller -B
	make Model -B
	make clean
	make configs.o
	make MenuElement.o
	${CXX} ${CXXFLAGS} -o sokoban main.cpp Model/obj.o View/obj.o Controller/obj.o configs.o MenuElement.o ${CXXLIBS} || make rm
	make clean
	make rm


configs.o: configs.cpp configs.hpp
	${CXX} ${CXXFLAGS} -c configs.cpp  ${CXXLIBS}

MenuElement.o: Elements/MenuElement.cpp Elements/MenuElement.hpp
	${CXX} ${CXXFLAGS} -c Elements/MenuElement.cpp  ${CXXLIBS}


View: View/MainDisplay.cpp View/MainDisplay.hpp View/BoardDisplay.cpp View/BoardDisplay.hpp View/EditorDisplay.cpp View/EditorDisplay.hpp View/MenuDisplay.cpp View/MenuDisplay.hpp View/CellDrawer.cpp View/CellDrawer.hpp
	${CXX} ${CXXFLAGS} -c View/MainDisplay.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c View/BoardDisplay.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c View/EditorDisplay.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c View/MenuDisplay.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c View/CellDrawer.cpp  ${CXXLIBS}
	ld -o View/obj.o -r MainDisplay.o BoardDisplay.o EditorDisplay.o MenuDisplay.o CellDrawer.o

Controller: Controller/MainController.cpp Controller/MainController.hpp Controller/GameBoardController.cpp Controller/GameBoardController.hpp Controller/EditorBoardController.cpp Controller/EditorBoardController.hpp Controller/EditorController.cpp Controller/EditorController.hpp Controller/MenuController.cpp Controller/MenuController.hpp
	${CXX} ${CXXFLAGS} -c Controller/MainController.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c Controller/GameBoardController.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c Controller/EditorBoardController.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c Controller/EditorController.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c Controller/MenuController.cpp  ${CXXLIBS}
	ld -o Controller/obj.o -r MainController.o GameBoardController.o EditorBoardController.o EditorController.o MenuController.o

Model: Model/Sokoban.cpp Model/Sokoban.hpp Model/Levels.cpp Model/Levels.hpp Model/Board.cpp Model/Board.hpp Model/Editor.cpp Model/Editor.hpp
	${CXX} ${CXXFLAGS} -c Model/Sokoban.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c Model/Levels.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c Model/Board.cpp  ${CXXLIBS}
	${CXX} ${CXXFLAGS} -c Model/Editor.cpp  ${CXXLIBS}
	ld -o Model/obj.o -r Sokoban.o Levels.o Board.o Editor.o


clean:
	rm *.o || echo -n ""

rm:
	rm View/obj.o || echo -n ""
	rm Controller/obj.o || echo -n ""
	rm Model/obj.o || echo -n ""
	
clean_all:
	make clean
	make rm
	rm sokoban ||echo -n ""
