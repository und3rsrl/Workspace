#include "Player.h"



Player::Player()
{
	std::cout << "Name:";
	std::cin >> this->namePlayer;

	std::cout << "Letter:";
	std::cin >> this->letterChosed;

	this->score = 0;

}

Player::~Player()
{
}

void Player::setScore() {
	this->score += 1;
}

void Player::setName(std::string name) {
	this->namePlayer = name;
}

void Player::setLetter(char letter) {
	this->letterChosed = letter;
}