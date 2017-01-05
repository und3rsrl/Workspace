#include "game.h"



game::game()
{	
}


game::~game()
{
}

void game::play() {

	char choice = 'Y';
	
	system("CLS");

	while (choice != 'N') {

		for (int turn = 0; turn < 9; turn++) {
			int x, y;

			print();

			if (turn % 2 == 0) {

				std::cout << "Player1 choose" << std::endl;
				std::cout << "X:"; std::cin >> x;
				std::cout << "Y:"; std::cin >> y;
				
				if (getTableLetter(x, y) == ' ') {

					setValue(player1.getLetter(), x, y);

				}

				else {

					while (getTableLetter(x, y) != ' ') {

						system("CLS");
						print();
						std::cout << "The case is not empty. Try again!" << std::endl;
						std::cout << "Player1 choose" << std::endl;
						std::cout << "X:"; std::cin >> x;
						std::cout << "Y:"; std::cin >> y;

					}

				}
				
				if (getCompletedCases() > 4) {
					if (verify(player1.getLetter())) {
						turn = 9;
						std::cout << "Player 1 Wins." << std::endl;
						player1.setScore();
					}
				}
			}

			else {
				std::cout << "Player2 choose" << std::endl;
				std::cout << "X:"; std::cin >> x;
				std::cout << "Y:"; std::cin >> y;


				if (getTableLetter(x, y) == ' ') {

					setValue(player2.getLetter(), x, y);

				}

				else {

					while (getTableLetter(x, y) != ' ') {

						system("CLS");
						print();
						std::cout << "The case is not empty. Try again!" << std::endl;
						std::cout << "Player2 choose" << std::endl;
						std::cout << "X:"; std::cin >> x;
						std::cout << "Y:"; std::cin >> y;

					}

					setValue(player2.getLetter(), x, y);

				}


				if (getCompletedCases() > 4) {

					if (verify(player2.getLetter())) {
						turn = 9;
						std::cout << "Player 2 Wins." << std::endl;
						player2.setScore();
					}

				}
			}

			system("CLS");
		}

		std::cout << player1.getName() << ":" << player1.getScore() << std::endl;
		std::cout << player2.getName() << ":" << player2.getScore() << std::endl;

		std::cout << "Do you want to play again? Y/N" << std::endl;
		std::cin >> choice;

		if (choice == 'Y' || choice == 'y') {

			newGame();
			system("CLS");

		}
	}
}

bool game::verify(char letter) {
	
	// Case 1
	for (int i = 0; i < 3; i++) {
		
		int count = 0;

		for (int j = 0; j < 3; j++) {
			
			if (getTableLetter(i, j) == letter) {
				count++;
			}

		}

		if (count == 3)
			return true;
	}

	// Case 2
	for (int i = 0; i < 3; i++) {

		int count = 0;

		for (int j = 0; j < 3; j++) {

			if (getTableLetter(j, i) == letter) {
				count++;
			}

		}

		if (count == 3)
			return true;
	}

	// Case 3
	int count = 0;
	for (int i = 0; i < 3; i++) {	
		
		if (getTableLetter(i, i) == letter) {
				count++;
		}

		if (count == 3)
			return true;
	}

	return false;
}

void game::newGame() {

	// Initialize number of completed cases
	setCompletly(0);

	// Initialize table
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			setValue(' ', row, col);
		}
	}

}

void game::print() {
	
	std::cout << player1.getName() << ":" << player1.getScore() << "             " << player2.getName() << ":" << player2.getScore() << std::endl;
	display();

}