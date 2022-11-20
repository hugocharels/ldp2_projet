CXX = g++
CXXFLAGS += -std='c++20' -Werror -Wall -Wextra -pedantic
LDFLAGS += -lfltk


main: main.cpp Sokoban.o Board.o
	${CXX} -o sokoban main.cpp Sokoban.o Board.o ${CXXFLAGS} ${LDFLAGS}
	make clean

Sokoban.o: Sokoban.cpp Sokoban.h
	${CXX} -c Sokoban.cpp ${CXXFLAGS}

Board.o: Board.cpp Board.h
	${CXX} -c Board.cpp ${CXXFLAGS}

clean :
	rm *.o
