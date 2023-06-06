#include "world.h"
#include<fstream>
#include<iostream>
#include<string>
#include"file_lib.h"
#include<array>

std::array<Card, count_off_all> load_config()
{
	std::array<Card, count_off_all> cards;
	std::string line;
	std::fstream f("config.txt", std::ios::in);
	if (f.is_open()) {
		short t = 0;
		short n = 0;
		while (std::getline(f, line)) {
			if (n > 6)
				n = 0, t += 1;
			if(n == 0)
				cards[t].card_num = std::stoi(line.substr(line.find(':') + 2));
			if (n == 1)
				cards[t].card_type = std::stoi(line.substr(line.find(':') + 2));
			if (n == 2)
				cards[t].mana = std::stoi(line.substr(line.find(':') + 2));
			if (n == 3)
				cards[t].attribute = std::stoi(line.substr(line.find(':') + 2));
			if (n == 4)
				cards[t].name = line.substr(line.find(':') + 2);
			if (n == 5)
				cards[t].value = std::stoi(line.substr(line.find(':') + 2));
			n += 1;
		}
		f.close();
	}
	else
		std::cout << "Unable to open file";
	return cards;
}

void load_world_entity_parametr(World& world, Entity& hero)
{
	std::string line;
	std::fstream f("default_config.txt", std::ios::in);
	if (f.is_open()) {
		short n = 0;
		while (std::getline(f, line)) {
			if (n == 1)
				hero.character.max_health = std::stoi(line.substr(line.find(':') + 2));
			if (n == 2)
				hero.character.max_mana = std::stoi(line.substr(line.find(':') + 2));
			if (n == 3)
				hero.character.luck = std::stoi(line.substr(line.find(':') + 2));
			if (n == 4)
				hero.character.quality = std::stoi(line.substr(line.find(':') + 2));
			if (n == 5)
				hero.character.affinity[0] = std::stoi(line.substr(line.find(':') + 2));
			if (n == 6)
				hero.character.affinity[1] = std::stoi(line.substr(line.find(':') + 2));
			if (n == 7)
				hero.character.affinity[2] = std::stoi(line.substr(line.find(':') + 2));
			if (n == 8)
				hero.character.affinity[3] = std::stoi(line.substr(line.find(':') + 2));
			if (n == 10)
				world.level = std::stoi(line.substr(line.find(':') + 2));
			if (n == 11)
				world.crystal_state = std::stoi(line.substr(line.find(':') + 2));
			if (n == 12)
				world.points = std::stoi(line.substr(line.find(':') + 2));
			if (n == 13)
				world.plus_points = std::stoi(line.substr(line.find(':') + 2));
			n += 1;
		}
		f.close();
	}
	else
		std::cout << "Unable to open file";
}