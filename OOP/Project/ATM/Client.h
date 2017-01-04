#pragma once
#include <string>


class Client
{
private:
	std::string name;
	int bankBalance;
	int amountDrawnToday;
	int PIN;
	bool blockedAccount;
	const int MAX_WITHDRAW_SUM = 5000;


public:
	Client();
	~Client();

	friend class ATM;
};

