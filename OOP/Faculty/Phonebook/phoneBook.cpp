#include "phoneBook.h"
#include <stdlib.h>
#include <windows.h>


phoneBook::~phoneBook()
{
}

void phoneBook::core()
{	
	int option = 99;
	while (option != 0)
	{

		std::cout << "1.Afisare contacte" << std::endl;
		std::cout << "2.Adaugare contact nou" << std::endl;
		std::cout << "3.Cauta contact" << std::endl;
		std::cout << "0.Iesire" << std::endl;

		std::cout << "Introduceti optiunea:" << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:
			if (first != 0)
			{
				subscriber* iterator;
				iterator = first;
				while (iterator != 0)
				{
					iterator->display();
					iterator = iterator->next;
				}
			}
			else 
			{
				std::cout << "Nu aveti contacte" << std::endl;
			}

			break;
		case 2:
			addContact();
			break;
		case 3:
			std::string contactName;
			std::cout << "Introduceti numele contactului:";
			std::cin >> contactName;
			searchContact(contactName);
			break;
		}

		Sleep(2500);
		system("CLS");
	}
}

void phoneBook::addContact()
{	
	std::string tempName;
	adress tempAdress;
	int tempNumber;

	std::cout << "Introduceti detaliile noului contact:" << std::endl;
	std::cout << "Nume:";
	std::cin >> tempName;
	std::cout << "Adresa:" << std::endl;
	std::cout << "City:";
	std::cin >> tempAdress.city;
	std::cout << "Street:";
	std::cin >> tempAdress.street;
	std::cout << "Numar:";
	std::cin >> tempNumber;

	subscriber *iterator;
	iterator = first;

	if (first == 0) 
	{
		first = iterator->Add(tempName, tempAdress, tempNumber);
	}
	else
	{
		while (iterator->next != 0) {
			iterator = iterator->next;
		}

		iterator->next = iterator->Add(tempName, tempAdress, tempNumber);
	}

	
	std::cout << "Contactul a fost adaugat cu succes:" << std::endl;

}

void phoneBook::searchContact(std::string contactName)
{
	if (first == 0) {
		std::cout << "Nu aveti contacte.";
	} 
	else
	{
		subscriber* iterator;
		iterator = first;

		while (iterator != 0)
		{	
			if (iterator->name == contactName)
			{
				std::cout << "Contactul a fost gasit. Doriti sa il afisez: y/n.";
				std::string choice;
				std::cin >> choice;
				system("CLS");

				if (choice == "y")
					iterator->display();

				break;
			}
			iterator = iterator->next;
		}
		std::cout << "Contactul nu a fost gasit" << std::endl;
	}
}
