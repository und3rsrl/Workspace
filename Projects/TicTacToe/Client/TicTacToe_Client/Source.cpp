#include <iostream>
#include "PlayerGame.h"
#include "Multiplayer.h"



int main()
{
	int choice = -1;
	
	while (choice != 0)
	{
		std::cout << "1) Player vs AI" << std::endl;
		std::cout << "2) Player vs Player" << std::endl;
		std::cout << "3) Multiplayer" << std::endl;

		std::cout << "Choice: ";
		std::cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
		{
			break;
		}
		case 2:
		{	
			PlayerGame game;
			game.play();
			break;
		}
		case 3:
		{
			Multiplayer game("127.0.0.1", 25565);
			game.play();
			break;
		}
		default:
			break;
		}
	}

	return 0;
}