#pragma once

#include <iostream>
#include <string>

class Player
{
private:
	std::string namePlayer;
	char letterChosed;
	int score;

public:

	Player();
	Player(std::string namePlayer, char letterChosed);
	~Player();

	int getScore() { return score; }
	char getLetter() { return letterChosed; }
	std::string getName() { return namePlayer; }

	void setScore();
	void setLetter(char letter);
	void setName(std::string name);
};

