#include "board.h"
#include <string>
//print verifie pour chaque case de la matrice MAP, si il n'y aurait pas un objet moveable (box ou player)
//si c'est le cas, un caractère correspondant est mis là
void print(){
	std::string to_print = "";

	for (int i=0; i<this->matrix.getCols(); i++) {
	    for (int j=0; i<this->matrix.getRows(); j++) {
	        
			if (Point{i,j} == this->player.getPos()) {
				to_print += "P";
			}

			else if ( contains(this->boxes, Point{i, j}) ) {
					to_print += "B";
			}

			else {
				to_print += this->matrix[i][j];
			}

		to_print += "\n";

	std::cout<<to_print<<std::endl;
}
