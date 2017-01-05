#include "CaineCuPete.h"



CaineCuPete::CaineCuPete()
{
}


CaineCuPete::~CaineCuPete()
{
}

void CaineCuPete::readInfo()
{
	int height, weight, age, noSpots;
	std::string name, color;

	std::cout << "Caine cu pete:" << std::endl;

	std::cout << "Nume:"; std::cin >> name;
	setName(name);

	std::cout << "Culoare:"; std::cin >> color;
	setColor(color);

	std::cout << "Inaltime:"; std::cin >> height;
	setHeight(height);

	std::cout << "Greutate:"; std::cin >> weight;
	setWeight(weight);

	std::cout << "Varsta:"; std::cin >> age;
	setAge(age);

	std::cout << "Numar pete:"; std::cin >> noSpots;
	setNoSpots(noSpots);
}

void CaineCuPete::displayInfo()
{
	std::cout << "Caine cu pete:" << std::endl;
	std::cout << "Nume:" << getName() << std::endl;
	std::cout << "Culoare:" << getColor() << std::endl;
	std::cout << "Inaltime:" << getHeight() << std::endl;
	std::cout << "Greutate:" << getWeight() << std::endl;
	std::cout << "Varsta:" << getAge() << std::endl;
	std::cout << "Nr. Pete:" << getNoSpots() << std::endl;
}
