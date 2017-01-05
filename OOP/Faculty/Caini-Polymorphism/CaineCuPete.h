#pragma once
#include "caine.h"
class CaineCuPete : public caine
{
private:
	int noSpots;

public:
	CaineCuPete();
	~CaineCuPete();

	void setNoSpots(int noSpots) {
		this->noSpots = noSpots;
	}

	int getNoSpots() {
		return noSpots;
	}

	void readInfo();
	void displayInfo();
};

