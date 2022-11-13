CXX = g++
CXXFLAGS += -std='c++20' -Werror -Wall -Wextra -pedantic
LDFLAGS += -lfltk


main: main.cpp sokoban.o board.o
	${CXX} -o sokoban main.cpp sokoban.o board.o ${CXXFLAGS}
	make fltk
	make clean

sokoban.o: sokoban.cpp sokoban.h
	${CXX} ${CXXFLAGS} sokoban.cpp -c ${CXXFLAGS}

board.o: board.cpp board.h
	${CXX} -c board.cpp ${CXXFLAGS}


fltk: interface.cpp interface.h sokoban.o board.o
	${CXX} -o interface interface.cpp sokoban.o board.o ${CXXFLAGS} ${LDFLAGS}


clean :
	rm *.o
