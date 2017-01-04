#pragma once
#include <iostream>
#include <string>
#include "adress.h"

class phoneBook
{
private:
	struct subscriber {
		std::string name;
		adress userAdress;
		int number;
		subscriber* next;

		subscriber(std::string contactName, adress contactAdress, int contactNumber, subscriber* p = 0) : name(contactName), userAdress(contactAdress), number(contactNumber), next(p) { }
		~subscriber() { next = 0; }

		subscriber* Add(std::string contactName, adress contactAdress, int contactNumber) 
		{
			
			subscriber* newContact = new subscriber(contactName, contactAdress, contactNumber);
			return newContact;
			
			
		}
		void display() const
		{ 
			std::cout << "Nume:" << name << std::endl; 
			userAdress.display();
			std::cout << "Number:" << number << std::endl;
			std::cout << std::endl;
		}
	};

	subscriber* first;

public:
	phoneBook() { first = 0; }
	~phoneBook();

	void core();
	void addContact();
	void searchContact(std::string contactName);
};

