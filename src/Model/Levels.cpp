#include "../include.hpp"
#include "Board.hpp"
#include "Levels.hpp"


void Levels::loadFiles() {
	this->files.clear();

	DIR *d;
	struct dirent *dir;
	d = opendir("levels");
	if (not d) { return; }

	while ((dir = readdir(d)) != NULL) {
		std::string tmp = dir->d_name;
		if (tmp[0] == '.') { continue; }
		this->files.push_back(tmp);
	}

	closedir(d);
	std::sort(this->files.begin(), this->files.end());
}


void Levels::createBoard(int idx, Board &board, int &best_score, int &step_limit) const {

	// Chargement du fichier JSON
	Json::Value root;
	Json::Reader reader;
	std::ifstream file("levels/" + this->files[idx]);
	if (not reader.parse(file, root)) {
		// Erreur de parsing
		std::cerr << "Error parsing file" << std::endl;
		return;
	}

	// Accès aux différentes valeurs du fichier JSON
	int rows = root["size"]["x"].asInt();
	int cols = root["size"]["y"].asInt();

	Json::Value matrix = root["matrix"];
	std::string str_map = Json::FastWriter().write(matrix);	

	str_map.erase(str_map.begin());
	str_map.erase(str_map.end()-2);
	
	while (str_map.find(",") != std::string::npos) {
		str_map.replace(str_map.find(","), 1, "\n");
	}
	str_map.erase(std::remove(str_map.begin(), str_map.end(), '\"'), str_map.end());

	// LOAD BOARD
	board.loadMap(rows, cols, str_map);
	board.loadBoxes(root["boxes"]);
	int player_pos_x = root["player_pos"]["x"].asInt();
	int player_pos_y = root["player_pos"]["y"].asInt();
	board.loadPlayer(Point{player_pos_x, player_pos_y});

	best_score = root["best_score"].asInt();
	step_limit = root["step_limit"].asInt();
}


void Levels::saveBoard(Board &board, int step_limit) {

	// POUR L'EDITEUR DE NIVEAU OWO

	Json::Value root;

	int idx = 0;
	for (const auto& box : *board.getTouBoxDeg()) {	
		root["boxes"][idx]["color"] = (int)box.getColor();
		root["boxes"][idx]["pos"]["x"] = box.getPos().x;
		root["boxes"][idx]["pos"]["y"] = box.getPos().y;
		idx++;
	}

	auto* map = board.getToutDeg();
	std::string line = "";
	for (int i = 0; i < map->getCols(); i++) {
		for (int j = 0; j < map->getRows(); j++) {

			for ( const auto& box : *board.getTouBoxDeg() ) {
				if ( box.getPos() == Point{i, j} ) {
					line += ColorToNum(box.getColor());
					continue;
				}
			}

			if (map->at(i, j)->getType() == TARGET) {
				line += ColorToLetter(dynamic_cast<Target*>(map->at(i, j).get())->getColor());
			}
			else if (map->at(i, j)->getType() == TP) {
				line += ColorToNum(dynamic_cast<Teleporter*>(map->at(i, j).get())->getColor());
			}
			else { line += (char)(map->at(i, j)->getType()); }
		}
		root["matrix"].append(line);
		line = "";
	}

	root["player_pos"]["x"] = board.getPlayerPTR()->getPos().x;
	root["player_pos"]["y"] = board.getPlayerPTR()->getPos().y;
	root["size"]["x"] = map->getCols();
	root["size"]["y"] = map->getRows();
	root["step_limit"] = step_limit;
	root["best_score"] = 0;

	std::string json_str = Json::StyledWriter().write(root);

	// Écrivez la chaîne de caractères dans le fichier JSON
	std::string path = "levels/level" + std::to_string(this->files.size()) + ".json";
	std::ofstream out(path);
	out.write(json_str.c_str(), json_str.size());

	this->loadFiles();
}


void Levels::updateBestScore(int idx, int new_best_score) {
	// Chargement du fichier JSON
	Json::Value root;
	Json::Reader reader;
	std::ifstream file("levels/" + this->files[idx]);
	if (not reader.parse(file, root)) {
		// Erreur de parsing
		std::cerr << "Error parsing file" << std::endl;
		return;
	}

	// Modifiez la valeur de la clé "best_score"
	root["best_score"] = new_best_score;

	// Utilisez un objet Json::StyledWriter pour écrire l'objet Json::Value dans une chaîne de caractères
	std::string json_str = Json::StyledWriter().write(root);

	// Écrivez la chaîne de caractères dans le fichier JSON
	std::ofstream out("levels/" + this->files[idx]);
	out.write(json_str.c_str(), json_str.size());
}
