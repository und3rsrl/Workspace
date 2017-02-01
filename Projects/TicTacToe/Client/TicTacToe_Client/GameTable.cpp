#include "GameTable.h"


GameTable::GameTable()
{

	// Initialize number of completed cases
	this->completedCases = 0;

	// Initialize table
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			this->table[i][j] = ' ';
		}
	}
}

GameTable::~GameTable()
{
}

char GameTable::getTableLetter(int position)
{	
	int row = decodeRow(position);
	int col = decodeCol(position);
	
	return table[row][col];
}

char GameTable::getTableLetter(int row, int col)
{
	return table[row][col];
}

void GameTable::display() {

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {
			if (j == 1)
				std::cout << "|" << this->table[i][j] << "|";
			else
				std::cout << this->table[i][j];

		}

		std::cout << std::endl << "------" << std::endl;

	}
}

void GameTable::setValue(char choice, int position) {

	int row = decodeRow(position);
	int col = decodeCol(position);

	this->table[row][col] = choice;
	this->completedCases += 1;

}

void GameTable::setValue(char choice, int row, int col)
{
	this->table[row][col] = choice;
	this->completedCases += 1;
}

void GameTable::setCompletly(int number)
{
	this->completedCases = number;
}
