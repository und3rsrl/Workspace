#pragma once
#include <iostream>
#include "GameTable.h"
#include "player.h"

class PlayerGame :public GameTable
{
private:
	Player player1;
	Player player2;

public:
	PlayerGame();
	~PlayerGame();

	void play();
	bool verify(char letter);
	void newPlayerGame();
	void print();

};