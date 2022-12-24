CXX = g++
CXXFLAGS += -std='c++20' -Werror -Wall -Wextra -pedantic -lfltk -lfltk_images -ljsoncpp


main: main.cpp Sokoban.o draw_map.o draw_menu.o DisplaySokoban.o menu_element.o Board.o configs.o 
	${CXX} -o sokoban main.cpp Sokoban.o draw_map.o draw_menu.o DisplaySokoban.o menu_element.o Board.o configs.o ${CXXFLAGS}
	make clean

Sokoban.o: game/Sokoban.cpp game/Sokoban.h
	${CXX} -c game/Sokoban.cpp ${CXXFLAGS}

DisplaySokoban.o: interface/DisplaySokoban.cpp interface/DisplaySokoban.h 
	${CXX} -c interface/DisplaySokoban.cpp ${CXXFLAGS}

draw_map.o: interface/draw_map.cpp interface/DisplaySokoban.h 
	${CXX} -c interface/draw_map.cpp ${CXXFLAGS}

draw_menu.o: interface/draw_menu.cpp interface/DisplaySokoban.h 
	${CXX} -c interface/draw_menu.cpp ${CXXFLAGS}

menu_element.o: interface/menu_element.cpp interface/menu_element.h 
	${CXX} -c interface/menu_element.cpp ${CXXFLAGS}	

Board.o: game/Board.cpp game/Board.h
	${CXX} -c game/Board.cpp ${CXXFLAGS}

configs.o: configs.cpp configs.h
	${CXX} -c configs.cpp ${CXXFLAGS}

clean :
	rm *.o || echo no changes
