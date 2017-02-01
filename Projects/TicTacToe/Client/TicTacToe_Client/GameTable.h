#pragma once
#include <iostream>
#include "player.h"

class GameTable
{
private:
	char table[3][3];
	int  completedCases;
	
	/*
		Mapping cases in gameTable
		0 1 2
      0|1 2 3
	  1|4 5 6
	  2|7 8 9
	*/

	int mappingTableCases[2][9] = { 
									{ 0, 0, 0, 1, 1, 1, 2, 2, 2 },
									{ 0, 1, 2, 0, 1, 2, 0, 1, 2 }
								  };

public:
	GameTable();
	~GameTable();

	int getCompletedCases() { return completedCases; } // Return number of completed cases on table.
	char getTableLetter(int position); // Return X, O or " " from position.
	char getTableLetter(int row, int col); // Return X, O or " " from position.

	int decodeRow(int positionInTable) { return mappingTableCases[0][positionInTable - 1]; } // Get row from mapping table with given position.
	int decodeCol(int positionInTable) { return mappingTableCases[1][positionInTable - 1]; } // Get col from mapping table with given position.

	void display();
	void setValue(char choice, int position);
	void setValue(char choice, int row, int col);
	void setCompletly(int number);
};