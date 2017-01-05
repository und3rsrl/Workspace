#include "CaineFaraPete.h"



CaineFaraPete::CaineFaraPete()
{
}


CaineFaraPete::~CaineFaraPete()
{
}

void CaineFaraPete::readInfo()
{
	int height, weight, age;
	std::string name, color;

	std::cout << "Caine fara pete:" << std::endl;

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

}

void CaineFaraPete::displayInfo()
{
	std::cout << "Caine fara pete:" << std::endl;
	std::cout << "Nume:" << getName() << std::endl;
	std::cout << "Culoare:" << getColor() << std::endl;
	std::cout << "Inaltime:" << getHeight() << std::endl;
	std::cout << "Greutate:" << getWeight() << std::endl;
	std::cout << "Varsta:" << getAge() << std::endl;
}
