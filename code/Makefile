CXX = g++
CXXFLAGS += -std='c++20' -Werror -Wall -Wextra -pedantic
LDFLAGS += -lfltk


main: main.cpp sokoban.o board.o
	${CXX} ${CXXFLAGS} -o sokoban main.cpp sokoban.o board.o
	make clean

sokoban.o: sokoban.cpp
	${CXX} ${CXXFLAGS} sokoban.cpp -c sokoban.o

board.o: board.cpp
	${CXX} ${CXXFLAGS} board.cpp -c board.o


fltk: interface.cpp
	${CXX} ${CXXFLAGS} -o interface interface.cpp ${LDFLAGS}


clean :
	rm *.o
