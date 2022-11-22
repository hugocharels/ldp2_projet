#include "configs.h"


COLOR charToColor(char x) {
	if (x == '2') { return COLOR::RED; }
	else if (x == '3') { return COLOR::YELLOW; }
	else if (x == '4') { return COLOR::BLUE; }
	else if (x == '5') { return COLOR::ORANGE; }
	else if (x == '5') { return COLOR::GREEN; }
	else if (x == '5') { return COLOR::PURPLE; }
	return COLOR::NONE;
}

