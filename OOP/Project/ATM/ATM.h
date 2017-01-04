#pragma once
#include "Client.h"
#include <vector>

class ATM
{
private:
	std::vector<Client> members;

public:
	ATM();
	~ATM();

	void createUser();
	Client accessUser();
	bool pinIsCorrect(Client &user);
	int balanceInquiry(Client &user);
	void depositMoney(Client &user);
	void withdrawMoney(Client &user, int amount);
	void transferMoney(Client &user1, Client &user2, int amount);
};

