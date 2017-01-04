#pragma once
#include <iostream>
#include <string>

class adress
{
private:
	friend class phoneBook;
	std::string city;
	std::string street;

	void display() const 
	{
		std::cout << "Adress:" << std::endl;
		std::cout << "City:" << city << std::endl;
		std::cout << "Street:" << street << std::endl;
	}
public:
	adress();
	~adress();
};

