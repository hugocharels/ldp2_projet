#include "../include.hpp"
#include "BoardDisplay.hpp"
#include "../Model/Cell/include.hpp"
#include "DrawCell.hpp"
#include "../images.hpp"


void BoardDisplay::draw() {
	auto* other_cells = model->getToutDeg(); //matrix map pointer
	Player* player = model->getPlayerPTR(); 
	auto* boxes = model->getTouBoxDeg(); //pointer vector box

	for (int i=0; i<other_cells->getRows(); i++){
		for (int j=0; j<other_cells->getCols(); j++){
			DrawCell(modelPosToDisplayPos(Point{i,j}), other_cells->at(i,j).get());
		}
	}
	// player
	DrawCell(modelPosToDisplayPos(player->getPos()), player);
	// box
	for (auto& box: *boxes){ DrawCell(modelPosToDisplayPos(box.getPos()), &box);}
    this->drawStatus();
}

void BoardDisplay::drawStatus() {
	TextRectangle{Point{300,550}, 500, 35, model->getStatus()}.print();
}