#include "Client.h"
#include <iostream>



Client::Client()
{
	std::cout << "Creare cont:" << std::endl;
	std::cout << "Introduceti numele dvs:" << std::endl;
	std::cin >> name;
	std::cout << "Balanta contului a fost setata la: 0 lei" << std::endl;
	bankBalance = 0;
	std::cout << "Introduce-ti codul PIN dorit(4 cifre):" << std::endl;
	std::cin >> PIN;

	blockedAccount = false;
	amountDrawnToday = 0;

}


Client::~Client()
{
}
