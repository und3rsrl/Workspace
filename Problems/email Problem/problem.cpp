#include "problem.h"
#include <fstream>
#include <deque>
#include <string>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

struct email
{
	int ordine;
	string subiect;
	string destinatar;
	int prioritate;
};

bool comparareEmailPrioritate(const email &email1, const email &email2) {
	if (email1.prioritate < email2.prioritate)
		return true;
	else
		return false;
}

bool comparareEmailOrdine(const email &email1, const email &email2) {
	if (email1.ordine < email2.ordine)
		return true;
	else
		return false;
}

bool checkExistance(const list<email>& list, const email &email1) {
	for (auto it : list)
		if (email1.destinatar == it.destinatar)
			return true;

	return false;
}


void problem() 
{
	int x, k, l, t, n;

	ifstream file;
	file.open("input.txt");
	
	file >> x; //numarul de minute la care se scaneaza coada de emailuri
	file >> k; //numarul de emailuri extrase din coada la fiecare x minute
	file >> l; //numarul de elemente din lista de trimitere
	file >> t; //momentul de timp la care se doreste aflarea continutului cozii de procesare si a listei de trimitere
	file >> n; //numarul de emailuri

	deque<email> coadaDeEmail;

	for (int i = 0; i < n; i++)
	{
		email email;
		string buffer;

		getline(file, buffer, ' ');

		if (buffer[0] == '\n') {
			buffer.erase(0, 1);
		}

		email.ordine = stoi(buffer);

		getline(file, buffer, ' ');
		email.subiect = buffer;

		getline(file, buffer, ' ');
		email.destinatar = buffer;

		getline(file, buffer, '\n');
		email.prioritate = stoi(buffer);

		coadaDeEmail.push_back(email);
	}


	sort(coadaDeEmail.begin(), coadaDeEmail.end(), comparareEmailOrdine);

	int count_min = 1;

	list<email>	listaTrimitere;

	while (true) 
	{	
		if (count_min == t) 
		{
			cout << "Coada de procesare :";

			for (auto it : coadaDeEmail) 
			{
				cout << it.subiect << ", ";
			}
			cout << "\nLista de trimitere : ";
			for (auto it : listaTrimitere) 
			{
				cout << it.subiect << ", ";
			}
			break;
		}
		
		if (count_min % x == 0)
		{
			for (int i = 0; i < k; i++)
			{	
				email selectat;
				selectat = coadaDeEmail[0];

				if (checkExistance(listaTrimitere, selectat))
				{
					coadaDeEmail.push_back(selectat);
					coadaDeEmail.pop_front();
				}
				else
				{
					listaTrimitere.push_back(coadaDeEmail[0]);
					coadaDeEmail.pop_front();
				}

			}

			listaTrimitere.sort(comparareEmailPrioritate);

		}

		if (listaTrimitere.size() == l) 
		{
			listaTrimitere.clear();
		}



		count_min++;
	}

	cout << endl;

}
