#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{	
	// Create 26 Items to store in the Hash Table.
	Node * A = new Node{ "Apple", nullptr };
	Node * B = new Node{ "Banana", nullptr };
	Node * C = new Node{ "Caterpillar", nullptr };
	Node * D = new Node{ "Dog", nullptr };
	Node * E = new Node{ "Elephant", nullptr };
	Node * F = new Node{ "Fedora", nullptr };
	Node * G = new Node{ "Goosebumps", nullptr };
	Node * H = new Node{ "House", nullptr };
	Node * I = new Node{ "Insects", nullptr };
	Node * J = new Node{ "Jam", nullptr };
	Node * K = new Node{ "Kite", nullptr };
	Node * L = new Node{ "Limestone", nullptr };
	Node * M = new Node{ "Mountaineering", nullptr };
	Node * N = new Node{ "Night", nullptr };
	Node * O = new Node{ "Open Sesame", nullptr };
	Node * P = new Node{ "Potatoes", nullptr };
	Node * Q = new Node{ "Quantum Mechanics", nullptr };
	Node * R = new Node{ "Rrrrrrrrrrawr", nullptr };
	Node * S = new Node{ "Snakes", nullptr };
	Node * T = new Node{ "Tizzy Tube", nullptr };
	Node * U = new Node{ "Underworld", nullptr };
	Node * V = new Node{ "Volcanic Ash", nullptr };
	Node * W = new Node{ "Who When What Why", nullptr };
	Node * X = new Node{ "XXX", nullptr };
	Node * Y = new Node{ "Yellow", nullptr };
	Node * Z = new Node{ "Zest of Lemon", nullptr };

	//Create a HashTable
	HashTable hashTable;

	//Add all elements to HashTable
	hashTable.insertItem(A);
	hashTable.insertItem(B);
	hashTable.insertItem(C);
	hashTable.insertItem(D);
	hashTable.insertItem(D);
	hashTable.insertItem(E);
	hashTable.insertItem(F);
	hashTable.insertItem(G);
	hashTable.insertItem(H);
	hashTable.insertItem(I);
	hashTable.insertItem(J);
	hashTable.insertItem(K);
	hashTable.insertItem(L);
	hashTable.insertItem(M);
	hashTable.insertItem(N);
	hashTable.insertItem(O);
	hashTable.insertItem(P);
	hashTable.insertItem(Q);
	hashTable.insertItem(R);
	hashTable.insertItem(S);
	hashTable.insertItem(T);
	hashTable.insertItem(U);
	hashTable.insertItem(V);
	hashTable.insertItem(W);
	hashTable.insertItem(X);
	hashTable.insertItem(Y);
	hashTable.insertItem(Z);

	//Print the HashTable
	hashTable.printTable();

	//Print the HashTable Histogram
	hashTable.printHistogram();

	//Remove A item
	hashTable.removeItem("Apple");
	hashTable.printTable();

	return 0;
}
