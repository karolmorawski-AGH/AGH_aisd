// listy-wiazane.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node
{
	int val;
	node* next;
	node* prev;
};

//pokaz liste
void show(node* H)
{
	node* p = H;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
}

//dodaj do listy dwustronnej
void add(node* &H, int x)
{
	node* tmp = new node;
	tmp->val = x;
	tmp->next = H;
	H = tmp;
	if (H != NULL)
	{
		tmp->prev = NULL;
	}
	else
	{
		tmp->next->prev = NULL;
	}
}

//czytaj z pliku
void readFile(char *filen, node *&H)
{
	ifstream f;
	f.open(filen);
	if (f.good())
	{
		int a;
		while (!f.eof())
		{
			f >> a;
			add(H, a);
		}
	}
}

//zamiana elementu o wartosci x ze swoim poprzednikiem
int swapPrev(node* &H, int x)
{
	node* p = H;
	node* s = H;
	if (p == NULL || p->next == NULL)
	{
		cout << "Blad\n";
		return 0;
	}
	while (p->next->next != NULL && p->next->next->val != x)
	{
		p = p->next;
	}

	if (p->next != NULL && p->next->next != NULL)
	{
		s = p->next;
		node* temp = new node;
		temp->val = p->next->val;
		p->next = s->next;
		temp->next = p->next->next;
		p->next->next = temp;
		delete s;
	}
}

//zamiana elementu o wartosci x ze swoim nastepnikiem
int swapNext(node* &H, int x)
{
	node* p = H;
	node* s = H;
	if (p == NULL || p->next == NULL)
	{
		cout << "Blad\n";
		return 0;
	}
	while (p->next->next != NULL && p->next->next->val != x)
	{
		p = p->next;
	}

	if (p->next != NULL && p->next->next != NULL)
	{
		//TODO nie dziala dla x=1(dodac wyjatek)
		s = p->next;
		node* temp = new node;
		temp->val = p->next->next->next->val;
		p->next->next->next = s->next->next->next;
		temp->next = p->next->next;
		p->next->next = temp;
		delete s;
	}


}

//wstawianie na na dana pozycje wartosci NAPRAWIC
void insert(node* &H, int x, int pos)
{
	node* temp = new node;
	temp->val = x;

	node* p = H;
	node* s = H;

	for (int i = 0; i < pos - 1; i++)
	{
		if (p->next != NULL)
		{
			p = p->next;
		}
		else
		{
			break;
		}
	}

	if (p->next != NULL)
	{
		p->val = temp->val;
		delete temp;
	}

}

//usuwanie elementu z pozycji
void rm(node* &H, int x)
{
	node* p = H;
	node* s = H;

	for (int i = 0; i<x - 2; i++)
	{
		if (p->next == NULL)
			return;
		p = p->next;
	}

	if (p->next != NULL && p != H)
	{
		s = p->next;
		p->next = s->next;
		delete s;
	}

	if (p->next == NULL)
	{

	}
}


//usuwanie elementow o podanej wartosci 

void rmVal(node* &H, int x)
{
	node* p = H;
	node* s = H;
	node* q = H;
	node* v = H;



	while (p->next != NULL && p->next->next != NULL)
	{

		if (p->next->val == x)
		{
			s = p->next;
			p->next = p->next->next;
			delete s;
			node* s = H;

		}

		p = p->next;
	}

	if (H->val == x)
	{
		q = H;
		H = H->next;
		delete q;
	}

	p = H;


	while (p->next->next != NULL)
	{
		p = p->next;
	}

	if (p->next->val == x)
	{
		delete p->next;
		p->next = NULL;
	}


}

void costam(node* &H)
{
	node* p = H;
	rmVal(H, p->next->val);
}



int main()
{
	node* H = NULL;

	cout << "Lista:\n";
	add(H, 12);
	add(H, 11);
	add(H, 10);
	add(H, 9);
	add(H, 8);
	add(H, 7);
	add(H, 6);
	add(H, 5);
	add(H, 4);
	add(H, 3);
	add(H, 2);
	add(H, 1);
	show(H);
	cout << endl << "Lista po:\n";
	costam(H);
	show(H);


	cout << endl << endl;
	system("pause");
	return 0;
}
