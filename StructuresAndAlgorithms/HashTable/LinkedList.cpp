#include "LinkedList.h"




LinkedList::LinkedList()
{
	head = new Node;
	head->next = nullptr;
	length = 0;
}


LinkedList::~LinkedList()
{
	Node* Iter = head;
	Node* Current;
	while (Iter->next != nullptr) // Iterate until last element in the list
	{	
		if (Iter != head)
		{
			Current = Iter;
			Iter = Iter->next;
			delete Current;
		}
	}
}

void LinkedList::addNode(Node* newNode)
{

	if (head->next == nullptr)
	{
		head->next = newNode;
		newNode->next = nullptr;
		length++;
		return;
	}

	Node* Iter = head;

	while (Iter->next != nullptr) // Iterate until last element in the list
	{	
		Iter = Iter->next;			
	}

	Iter->next = newNode; // chain the new value to the last value in the list
	newNode->next = nullptr;
	length++;
}

bool LinkedList::removeNode(std::string	value)
{
	if (head->next == nullptr)
		return false;

	Node* Iter = head;

	while (Iter->next != nullptr && Iter->next->value != value) // Iterate until last element in the list
	{	
		
		Iter = Iter->next;
	}

	Node* nodeToRemove = Iter->next;
	Iter->next = nodeToRemove->next;

	delete nodeToRemove;
}


Node* LinkedList::getNode(std::string value)
{
	Node* Iter = head;

	while (Iter->next != nullptr) // Iterate until last element in the list
	{
		Iter = Iter->next;
		if (Iter->value == value)
		{
			return Iter;
		}
	}

	return nullptr;
}

void LinkedList::printList()
{
	if (length == 0)
	{
		std::cout << "\n{ }\n";
		return;
	}

	std::cout << "\n{ ";
	Node* Iter = head;

	while (Iter->next != nullptr) // Iterate until last element in the list
	{
		Iter = Iter->next;
		
		std::cout << Iter->value;

		if (Iter->next)
			std::cout << ", ";
		else
			std::cout << " ";
	}

	std::cout << "}\n";
}



int LinkedList::getLength()
{
	return length;
}

void LinkedList::searchValue(Node * head, int value)
{

}
