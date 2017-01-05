#include "player.h"



player::player()
{
	std::cout << "Name:";
	std::cin >> this->namePlayer;

	std::cout << "Letter:";
	std::cin >> this->letterChosed;

	this->score = 0;

}

player::~player()
{
}

void player::setScore() {
	this->score += 1;
}

void player::setName(std::string name) {
	this->namePlayer = name;
}

void player::setLetter(char letter) {
	this->letterChosed = letter;
}