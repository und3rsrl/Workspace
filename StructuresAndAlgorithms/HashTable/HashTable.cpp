#include "HashTable.h"



int HashTable::hash(std::string itemValue)
{	
	int value = 0;

	for (int i = 0; i < itemValue.length(); i++)
	{
		value += itemValue[i];
	}

	return (value * itemValue.length()) % length;
}

HashTable::HashTable(int tableLength)
{
	if (tableLength <= 0) tableLength = 13;
	array = new LinkedList[tableLength];
	length = tableLength;
}

void HashTable::insertItem(Node * newItem)
{
	int index = hash(newItem->value);
	array[index].addNode(newItem);
}

bool HashTable::removeItem(std::string value)
{
	int index = hash(value);
	return array[index].removeNode(value);
}

Node * HashTable::getItem(std::string value)
{
	int index = hash(value);
	return array[index].getNode(value);
}

void HashTable::printTable()
{
	std::cout << "\n\nHash Table:";
	for (int i = 0; i < length; i++)
	{
		std::cout << "Bucket " << i + 1 << ": ";
		array[i].printList();
	}
}

void HashTable::printHistogram()
{
	std::cout << "\n\nHash Table Contains ";
	std::cout << getNumberOfItems() << "Items total\n";

	for (int i = 0; i < length; i++)
	{
		std::cout << i + 1 << ":\t";
		for (int j = 0; j < array[i].getLength(); j++)
		{
			std::cout << " X";
		}
		std::cout << "\n";
	}
}

int HashTable::getLength()
{
	return length;
}

int HashTable::getNumberOfItems()
{
	int itemCount = 0;

	for (int i = 0; i < length; i++)
	{
		itemCount += array[i].getLength();
	}

	return itemCount;
}

HashTable::~HashTable()
{
	delete[] array;
}
