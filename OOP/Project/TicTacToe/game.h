#pragma once

#include <iostream>
#include "gameTable.h"
#include "player.h"

class game:public gameTable
{
private:
	player player1;
	player player2;

public:
	game();
	~game();
	
	void play();
	bool verify(char letter);
	void newGame();
	void print();

};

