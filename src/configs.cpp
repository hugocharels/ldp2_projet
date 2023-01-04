#include "include.hpp"
#include "configs.hpp"


COLOR charToColor(char x) {
	if (x == '2' or x == 'B') { return COLOR::RED; }
	else if (x == '3' or x == 'C') { return COLOR::YELLOW; }
	else if (x == '4' or x == 'D') { return COLOR::BLUE; }
	else if (x == '5' or x == 'E') { return COLOR::ORANGE; }
	else if (x == '6' or x == 'F') { return COLOR::GREEN; }
	else if (x == '7' or x == 'G') { return COLOR::PURPLE; }
	else if (x == '8' or x == 'H') { return COLOR::PINK; }
	return COLOR::NONE;
}

char ColorToNum(COLOR color) {
	switch(color) {
		case COLOR::NONE: return '1';
		case COLOR::RED: return '2';
		case COLOR::YELLOW: return '3';
		case COLOR::BLUE: return '4';
		case COLOR::ORANGE: return '5';
		case COLOR::GREEN: return '6';
		case COLOR::PURPLE: return '7';
		case COLOR::PINK: return '8';
	} return '1';
}

char ColorToLetter(COLOR color) {
	switch(color) {
		case COLOR::NONE: return 'A';
		case COLOR::RED: return 'B';
		case COLOR::YELLOW: return 'C';
		case COLOR::BLUE: return 'D';
		case COLOR::ORANGE: return 'E';
		case COLOR::GREEN: return 'F';
		case COLOR::PURPLE: return 'G';
		case COLOR::PINK: return 'H';
	} return 'A';
}


COLOR intToColor(int x) {
	switch(x) {
		case 2: return COLOR::RED;
		case 3: return COLOR::YELLOW;
		case 4: return COLOR::BLUE;
		case 5: return COLOR::ORANGE;
		case 6: return COLOR::GREEN;
		case 7: return COLOR::PURPLE;
		case 8: return COLOR::PINK;
	} return COLOR::NONE;
}

int mod(int x, int y) {
	int res = x%y;
	if (res < 0) { res = y+res; }
	return res;
}
