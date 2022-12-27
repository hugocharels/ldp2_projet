#include <iostream>
#include <fstream>
#include <json/json.h>
#include <dirent.h>

#include "Board.h"
#include "Levels.h"




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


void Levels::saveBoard(Board &board) {

	// POUR L'EDITEUR DE NIVEAU OWO
	std::cout << &board << std::endl;
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
	std::ofstream out("file.json");
	out.write(json_str.c_str(), json_str.size());
}
