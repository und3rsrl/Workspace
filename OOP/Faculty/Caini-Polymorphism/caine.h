#pragma once
#include <iostream>
#include <string>


class caine
{
private:
	std::string name;
	int height;
	int weight;
	int age;
	std::string color;

public:
	caine();
	~caine();
	virtual void readInfo() = 0;
	virtual void displayInfo() = 0;
	
	void setName(std::string name) {
		this->name = name;
	}

	std::string getName() {
		return name;
	}

	void setHeight(int height) {
		this->height = height;
	}

	int getHeight() {
		return height;
	}

	void setWeight(int weight) {
		this->weight = weight;
	}

	int getWeight() {
		return weight;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return age;
	}

	void setColor(std::string color) {
		this->color = color;
	}

	std::string getColor() {
		return color;
	}
};

