#pragma once
#include "ATM.h"

class Client
{
private:
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

