#pragma once

#include "LinkedList.h"

class HashTable
{
private:

	LinkedList * array;

	int length;

	int hash(std::string itemValue);


public:
	HashTable(int tableLength = 13);

	void insertItem(Node* newItem);
	bool removeItem(std::string value);
	Node* getItem(std::string value);
	void printTable();
	void printHistogram();
	int getLength();
	int getNumberOfItems();

	~HashTable();
};

