#ifndef _SOKOBAN_H
#define _SOKOBAN_H

#include "board.h"


class Sokoban {

	Board board;

public:

	Sokoban()=default;
	~Sokoban()=default;
 	
 	void changeState(MOVE move);
 	
 	bool win();

 	void draw();
}


#endif