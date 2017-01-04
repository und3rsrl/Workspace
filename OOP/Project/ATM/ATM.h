#pragma once
#include "Client.h"

class ATM
{
public:
	ATM();
	~ATM();

	bool pinIsCorrect(Client & user);
	int balanceInquiry(Client & user);
	int depositMoney(Client & user);
	int withdrawMoney(Client & user);
	int transferMoney(Client & user1, Client & user2);
};

