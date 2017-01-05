#include "CaineCuPete.h";
#include "CaineFaraPete.h"

int main() {

	
	int choice;

	std::cout << "Alegeti tipul de caine:" << std::endl;
	std::cout << "1.Caine cu pete" << std::endl;
	std::cout << "2.Caine fara pete" << std::endl;

	std::cin >> choice;

	switch (choice) {
	
	case 1: {

		caine *caine = new CaineCuPete();
		caine->readInfo();
		std::cout << std::endl;
		caine->displayInfo();
		}
	case 2: {
		caine *caine = new CaineFaraPete();
		caine->readInfo();
		std::cout << std::endl;
		caine->displayInfo();
		}
	}

	return 0;
}