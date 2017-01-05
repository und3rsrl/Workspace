#pragma once

#include <iostream>
#include <string>

class player
{
private:
	std::string namePlayer;
	char letterChosed;
	int score;

public:
	
	player();
	player(std::string namePlayer, char letterChosed);
	~player();

	int getScore() { return score; }
	char getLetter() { return letterChosed; }
	std::string getName() { return namePlayer; }

	void setScore();
	void setLetter(char letter);
	void setName(std::string name);
};

