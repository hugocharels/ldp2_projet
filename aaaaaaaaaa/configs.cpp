#include "configs.h"


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
