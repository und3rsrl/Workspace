#include "gameTable.h"


gameTable::gameTable()
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

gameTable::~gameTable()
{
}

void gameTable::display() {
	
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

void gameTable::setValue(char choice, int row, int col) {
	
	this->table[row][col] = choice;
	this->completedCases += 1;

}

void gameTable::setCompletly(int number)
{
	this->completedCases = number;
}
