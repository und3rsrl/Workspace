#pragma once

#include <iostream>
#include "player.h"

class gameTable
{
private:
	char table[3][3];
	int  completedCases;
	
public:
	gameTable();
	~gameTable();

	int getCompletedCases() { return completedCases; }
	char getTableLetter(int row, int col) { return table[row][col]; }

	void display();
	void setValue(char choice, int row, int col);
	void setCompletly(int number);
};

