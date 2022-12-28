CXX = g++
CXXFLAGS += -std='c++20' -Werror -Wall -Wextra -pedantic -lfltk -lfltk_images -ljsoncpp

main: main.cpp
	make View -B || make clean
	make Controller -B || make clean
	make Model -B || make clean
	make clean
	make configs.o
	clear
	${CXX} ${CXXFLAGS} -o sokoban main.cpp View/obj.o Controller/obj.o Model/obj.o configs.o || make rm
	make clean


configs.o: configs.cpp configs.hpp
	${CXX} ${CXXFLAGS} -c configs.cpp

View: View/MainDisplay.cpp View/MainDisplay.hpp View/BoardDisplay.cpp View/BoardDisplay.hpp View/EditorDisplay.cpp View/EditorDisplay.hpp View/MenuDisplay.cpp View/MenuDisplay.hpp
	${CXX} ${CXXFLAGS} -c View/MainDisplay.cpp
	${CXX} ${CXXFLAGS} -c View/BoardDisplay.cpp
	${CXX} ${CXXFLAGS} -c View/EditorDisplay.cpp
	${CXX} ${CXXFLAGS} -c View/MenuDisplay.cpp
	ld -o View/obj.o -r MainDisplay.o BoardDisplay.o EditorDisplay.o MenuDisplay.o

Controller: Controller/MainController.cpp Controller/MainController.hpp Controller/BoardController.cpp Controller/BoardController.hpp Controller/EditorController.cpp Controller/EditorController.hpp Controller/MenuController.cpp Controller/MenuController.hpp
	${CXX} ${CXXFLAGS} -c Controller/MainController.cpp
	${CXX} ${CXXFLAGS} -c Controller/BoardController.cpp
	${CXX} ${CXXFLAGS} -c Controller/EditorController.cpp
	${CXX} ${CXXFLAGS} -c Controller/MenuController.cpp
	ld -o Controller/obj.o -r MainController.o BoardController.o EditorController.o MenuController.o

Model: Model/Sokoban.cpp Model/Sokoban.hpp Model/Levels.cpp Model/Levels.hpp Model/Board.cpp Model/Board.hpp
	${CXX} ${CXXFLAGS} -c Model/Sokoban.cpp
	${CXX} ${CXXFLAGS} -c Model/Levels.cpp
	${CXX} ${CXXFLAGS} -c Model/Board.cpp
	ld -o Model/obj.o -r Sokoban.o Levels.o Board.o


clean:
	rm *.o || echo -n ""

rm:
	rm View/obj.o || echo -n ""
	rm Controller/obj.o || echo -n ""
	rm Model/obj.o || echo -n ""
	rm sokoban ||echo -n ""
