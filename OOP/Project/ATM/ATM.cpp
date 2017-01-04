#include "ATM.h"
#include <iostream>


ATM::ATM()
{
}


ATM::~ATM()
{
}

void ATM::createUser()
{
	Client temp;
	members.push_back(temp);
}

Client* ATM::accessUser()
{	
	if (members.size() == 0) {
		throw "Nu exista niciun membru.";
	}

	for (int noUser = 0; noUser < members.size(); noUser++) {
		std::cout << noUser + 1 << ". " << members[noUser].name << std::endl;
	}

	int choice;
	std::cout << "Alegere: "; std::cin >> choice;

	return &members[choice - 1];
}

bool ATM::pinIsCorrect(Client &user)
{
	int PIN;
	int mistakes = 0;

	std::cout << "Introduce-ti PIN-ul" << std::endl;
	std::cin >> PIN;

	while(PIN != user.PIN)
	{	
		mistakes += 1;

		if (mistakes == 3) {
			user.blockedAccount = true;
			throw "Contul a fost blocat";
		}
			

		std::cout << "Introduce-ti PIN-ul";
		std::cin >> PIN;
	} 

	std::cout << "PIN acceptat" << std::endl;

	return true;
}

int ATM::balanceInquiry(Client & user)
{
	return user.bankBalance;
}

void ATM::depositMoney(Client & user)
{
	int amount;

	std::cout << "Introduceti suma dorita";
	std::cin >> amount;

	user.bankBalance += amount;

	std::cout << "Suma a fost adaugata cu succes! Noul sold este: " << user.bankBalance;
}

void ATM::withdrawMoney(Client & user, int amount)
{

	if (amount > user.bankBalance) {
		throw "Fonduri insuficiente";
	}

	if (user.amountDrawnToday == user.MAX_WITHDRAW_SUM) {
		throw "Ai atins limita de 5000 lei/zi.";
	}

	user.bankBalance -= amount;
	user.amountDrawnToday += amount;

	std::cout << "Suma a fost extrasa cu succes! Noul sold este: " << user.bankBalance;
}

void ATM::transferMoney(Client & user1, Client & user2, int amount)
{
	

	if (amount > user1.bankBalance) {
		throw "Fonduri insuficiente";
	}

	user1.bankBalance -= amount;
	user2.bankBalance += amount;

	std::cout << "Suma a fost transferata cu succes! Noul sold este: " << std::endl 
																	   << "Client1: " << user1.bankBalance
																	   << "Client2: " << user2.bankBalance;
}

