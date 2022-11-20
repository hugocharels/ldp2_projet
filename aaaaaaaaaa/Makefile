CXX = g++
CXXFLAGS += -std='c++20' -Werror -Wall -Wextra -pedantic
LDFLAGS += -lfltk


main: main.cpp sokoban.o board.o
	${CXX} -o sokoban main.cpp sokoban.o board.o ${CXXFLAGS} ${LDFLAGS}
	make clean

sokoban.o: sokoban.cpp sokoban.h
	${CXX} -c sokoban.cpp ${CXXFLAGS}

board.o: board.cpp board.h
	${CXX} -c board.cpp ${CXXFLAGS}

clean :
	rm *.o
