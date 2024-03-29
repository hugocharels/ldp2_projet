#include "../include.hpp"
#include "Board.hpp"


Point getNextPos(const MoveableCell &obj, MOVE move) {
	int x = obj.getPos().x;
	int y = obj.getPos().y;
	switch (move) {
		case MOVE::UP: x--; break;
		case MOVE::DOWN: x++; break;
		case MOVE::LEFT: y--; break;
		case MOVE::RIGHT: y++; break;
		case MOVE::INVALID: break;
	}
	return Point{x, y};
}


// PUBLIC 

// PLAY

bool Board::play(MOVE move) {
	if (move == MOVE::INVALID) { return false; }
	if (this->canPlayerMove(move)) {
		if (this->moveBoxOnMove(move)) {
			player.move(move);
			this->movePlayerOnTp();
		}
	}
	return true;
}

bool Board::win() const {
	for (auto &box : this->boxes) {
		if (not box.onTarget()) { return false; }
	} return true;
}

// si num of blocked box > num target - num box
bool Board::loose() const {
	unsigned short num_blocked_box = 0;
	for (const auto &box : this->boxes) {
		if (not box.onTarget() and this->blockedBox(box)) { 
			num_blocked_box++;
			if ( this->boxes.size() - num_blocked_box < this->target_nb ) {
				return true;
			}
		}
	} return false;
}



// LOAD

void Board::loadMap(int rows, int cols, std::string &str_map) {

	std::vector<std::tuple<int, int, char, Teleporter*>> tp_vector;
	this->target_nb = 0;

	this->map.resize(rows, cols);
	int i = 0, j = 0;		//actual pos
	for (auto c : str_map) {
		if (c == '\n') { ++i; j=0; continue; }
		if (c == (char)CELL::WALL) { this->map.at(i, j) = std::make_unique<Cell>(CELL::WALL); }
		else if (c == (char)CELL::EMPTY) { this->map.at(i, j) = std::make_unique<Cell>(CELL::EMPTY); }
		else if (isdigit(c)) { this->map.at(i, j) = std::make_unique<Target>(charToColor(c)); this->target_nb++; }
		else { 
			this->map.at(i, j) = std::make_unique<Teleporter>(charToColor(c));
			auto tp_info = std::make_tuple(i, j, c, dynamic_cast<Teleporter*>(this->map.at(i, j).get()));
			tp_vector.push_back(tp_info);
		}
		++j;
	}

	//teleporter association destination
	while (not tp_vector.empty()) {
		auto current = tp_vector.back();
		tp_vector.pop_back();
		int idx = 0;
		for (auto &elem : tp_vector) {
			if (std::get<2>(elem) == std::get<2>(current)) {
				std::get<3>(current)->setDestination(Point{std::get<0>(elem),std::get<1>(elem)});
				std::get<3>(elem)->setDestination(Point{std::get<0>(current),std::get<1>(current)});
				tp_vector.erase(tp_vector.begin()+idx);
				break;
			}
			idx++;
		}
	}

}


void Board::loadBoxes(Json::Value &boxes_info) {
	this->boxes.clear();
    for (unsigned int i = 0; i < boxes_info.size(); ++i) {
        int x = boxes_info[i]["pos"]["x"].asInt();
        int y = boxes_info[i]["pos"]["y"].asInt();
        int color = boxes_info[i]["color"].asInt();
		this->boxes.push_back(Box{Point{x, y}, intToColor(color)});
	}
}



void Board::print() const {
	std::string to_print = "";
	for (int i=0; i<this->map.getRows(); i++) {
	    for (int j=0; j<this->map.getCols(); j++) {
			if (this->player.getPos() == Point{i,j}) {
				to_print += "P";
			} else if (this->boxHere(Point{i,j})) {
				to_print += "B";
			} else {
				to_print += (char)this->map.at(i, j)->getType();
			}
		}
		to_print += "\n";
	}
	std::cout<<to_print<<std::endl;
}


bool Board::inMap(int x, int y) const {
	return x > 0 and x < this->map.getRows()-1 and y > 0 and y < this->map.getCols()-1 ;
}

void Board::removeIfBox(Point pos) {
	int idx = 0;
	for (const auto &box : this->boxes) {
		if (pos == box.getPos()) {
			this->boxes.erase(this->boxes.begin() + idx);
			return;
		} idx++;
	}
}

bool Board::boxHere(Point pos) const {
	for (const auto &box : this->boxes) {
		if (pos == box.getPos()) {
			return true;
		}
	}
	return false;
}


// PRIVATE

// CAN MOVE

bool Board::canPlayerMove(MOVE move) const {
	Point next_pos = getNextPos(this->player, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y)) { return false; }
	return this->map.at(x, y)->walkable();
}

bool Board::canBoxMove(Box &box, MOVE move) const {
	Point next_pos = getNextPos(box, move);
	int x = next_pos.x;
	int y = next_pos.y;
	if (not this->inMap(x, y) or this->boxHere(Point{x, y})) { return false; }
	return this->map.at(x, y)->walkable();
}


// MOVE

bool Board::moveBoxOnMove(MOVE move) {
	Point next_pos = getNextPos(this->player, move);

	// return if a box is on target or not
	auto onTarget = [this](const Box& box) {
		return *(this->map.at(box.getPos().x, box.getPos().y)) == CELL::TARGET and 
		dynamic_cast<Target*>(map.at(box.getPos().x, box.getPos().y).get())->getColor() == box.getColor();
	};

	for (auto &box : this->boxes) {
		if (not (box.getPos() == next_pos)) { continue; } 
		if (not canBoxMove(box, move)) { return false; }
		box.move(move);
		box.setTarget(onTarget(box));
		return true;
	} return true;
}

void Board::movePlayerOnTp() {
	int x = this->player.getPos().x;
	int y = this->player.getPos().y;

	if (*(this->map.at(x, y)) == CELL::TP) {
		Point tp_pos = dynamic_cast<Teleporter*>(this->map.at(x, y).get())->getTpPos();
		if (not this->boxHere(tp_pos)) {
			this->player.tp(tp_pos);
		}
	}
}


bool Board::blockedBox(const Box &box) const {
	int x, y;
	x = box.getPos().x;
	y = box.getPos().y;
	std::array<bool, 4> free_pos{false, false, false, false};
	if (this->inMap(x+1, y) and this->map.at(x+1, y)->walkable()) {
		free_pos[0] = true;
	} if (this->inMap(x, y+1) and this->map.at(x, y+1)->walkable()) {
		free_pos[1] = true;
	} if (this->inMap(x-1, y) and this->map.at(x-1, y)->walkable()) {
		free_pos[2] = true;
	} if (this->inMap(x, y-1) and this->map.at(x, y-1)->walkable()) {
		free_pos[3] = true;
	}
	for (int i=0;  i < 4; i++) {
		if (not free_pos[i] and not free_pos[(i+1)%4]) {
			return true;
		}
	} return false;
}
