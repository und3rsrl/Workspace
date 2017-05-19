#pragma once
#include <iostream>
#include <string>

typedef struct Node {
	std::string value;
	Node *next;
};

class LinkedList
{
	


private:
	Node *head;
	int length;

public:

	

	LinkedList();
	~LinkedList();

	void addNode(Node* newNode);
	bool removeNode(std::string value);
	Node* getNode(std::string value);
	void printList();
	int getLength();
	void searchValue(Node *head, int value);
};

