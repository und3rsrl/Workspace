#include "ATM.h"
#include <iostream>


ATM::ATM()
{
}


ATM::~ATM()
{
}

bool ATM::pinIsCorrect(Client &user)
{
	int PIN;
	int mistakes = 0;

	std::cout << "Introduce-ti PIN-ul";
	std::cin >> PIN;

	while(mistakes)
	if (PIN == user.PIN) {
		return 0;
	}
}

int ATM::balanceInquiry(Client & user)
{
	return user.bankBalance;
}

int ATM::depositMoney(Client & user, int amount)
{
	
}

int ATM::withdrawMoney(Client & user)
{
	return 0;
}

int ATM::transferMoney(Client & user1, Client & user2)
{
	return 0;
}

