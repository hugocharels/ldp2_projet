CXX = g++
CXXFLAGS += -std='c++20' -Werror -Wall -Wextra -pedantic
LDFLAGS += -lfltk


main: main.cpp Sokoban.o Board.o configs.o
	${CXX} -o sokoban main.cpp Sokoban.o Board.o configs.o ${CXXFLAGS} ${LDFLAGS}
	make clean

Sokoban.o: game/Sokoban.cpp game/Sokoban.h
	${CXX} -c game/Sokoban.cpp ${CXXFLAGS}

Board.o: game/Board.cpp game/Board.h
	${CXX} -c game/Board.cpp ${CXXFLAGS}

configs.o: configs.cpp configs.h
	${CXX} -c configs.cpp ${CXXFLAGS}

clean :
	rm *.o && rm sokoban || rm sokoban || echo no changes
