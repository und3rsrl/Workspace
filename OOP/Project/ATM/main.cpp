#include "client.h"
#include "atm.h"
#include <iostream>


int main() 
{

	ATM atm;

	int choice = -1;

	while (choice != 0) {
		std::cout << "Optiuni:" << std::endl;
		std::cout << "1. Creeaza utilizator" << std::endl;
		std::cout << "2. Acceseaza cont" << std::endl;
		std::cout << "0. Exit" << std::endl;


		std::cout << "Alegere: "; std::cin >> choice;

		try
		{

			switch (choice)
			{
			case 1:
				atm.createUser();
				break;


			case 2: {
				Client* user = atm.accessUser();

				if (atm.pinIsCorrect(*user))
				{

					std::cout << "Optiuni:" << std::endl;
					std::cout << "1. Depune bani" << std::endl;
					std::cout << "2. Retrage bani" << std::endl;
					std::cout << "3. Transfera bani" << std::endl;
					std::cout << "4. Sold disponibil" << std::endl;
					std::cout << "0. Exit" << std::endl;

					std::cout << "Alegere: "; std::cin >> choice;

					switch (choice)
					{
					case 1:
						atm.depositMoney(*user);
						break;


					case 2: {
						int amount;

						std::cout << "Introduceti suma dorita";
						std::cin >> amount;

						atm.withdrawMoney(*user, amount);
						break;
						}


					case 3: {
						int amount;

						std::cout << "Introduceti suma dorita pentru transfer";
						std::cin >> amount;

						atm.transferMoney(*user, *atm.accessUser(), amount);
						break;
						}


					case 4:
						std::cout << "Soldul dvs. este: " << atm.balanceInquiry(*user) << std::endl;
						break;


					case 0:
						break;
					}
				}
				break;
			}

			case 0:
				break;

			}
		}
		catch (const char* msg)
		{
			std::cerr << msg << std::endl;
		}
	}


	return 0;
}