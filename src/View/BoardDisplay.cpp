#include "../include.hpp"
#include "BoardDisplay.hpp"
#include "../Model/Cell/include.hpp"
#include "CellDrawer.hpp"
#include "../images.hpp"


// PUBLIC

void BoardDisplay::draw() {
	this->drawMap();
	this->drawPlayer();
	this->drawBoxes();
    this->drawStatus();
}


// PRIVATE

void BoardDisplay::drawMap() {
	Matrix<std::unique_ptr<Cell>>* cells = model->getMap();
	for (int i=0; i<cells->getRows(); i++){
		for (int j=0; j<cells->getCols(); j++){
			CellDrawer{modelPosToDisplayPos(Point{i,j}), cells->at(i,j).get()};
		}
	}
}

void BoardDisplay::drawPlayer() {
	Player* player = model->getPlayer();
	CellDrawer{modelPosToDisplayPos(player->getPos()), player};
}

void BoardDisplay::drawBoxes() {
	auto* boxes = model->getBoxes();
	for (auto& box: *boxes) {
		CellDrawer{modelPosToDisplayPos(box.getPos()), &box};
	}
}

void BoardDisplay::drawStatus() {
	TextRectangle{Point{300,550}, 500, 35, model->getStatus()}.print();
}
