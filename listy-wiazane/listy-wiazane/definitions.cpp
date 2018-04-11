#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "node.h"

using namespace std;

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
void swapPrev(node* &H, int x)
{
	node* p = H;
	node* s = H;
	
	for (int i = 1; i < x ; i++)
	{
		p = p->next;
	}
	node* tmp = new node;
	s = p->next;
	tmp->val = p->val;
	p->val = s->val;
	s->val = tmp->val;
	delete tmp;

	
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

//dzielenie listy na 2 (input: pozycja i Header)
void divide_list(node* &H, int x)
{
	//sprawdzanie liczy elementow w liscie
	node* p = H;
	int l_el = 0;

	while (p != NULL)
	{
		l_el = l_el + 1;
		p = p->next;
	}
	//wskaznik pomocniczy wraca na pierwszy element
	p = H;
	//tworzenie drugiej listy
	node*H2 = new node;

	//IF X!=0 OR X<L_EL

	if (x > l_el || x == 0)
	{
		cout << "---------------------" << endl;
		cout << "BLAD - wykroczono poza zakres lub lista jest pusta";
		cout << endl << "---------------------" << endl<<endl;
		return;
	}

	else
	{
		for (int i = 1; i < x - 1; i++)
		{
			p = p->next;
		}

		H2 = p->next;
		p->next = NULL;

		//pokazanie dwóch list
		cout << "---------------------" << endl;
		cout << "Pierwsza polowa listy (H1):     ";
		show(H);
		cout << endl << "Druga polowa listy (H2):        ";
		show(H2);
		cout << endl << "---------------------" << endl<<endl;
	}
	
}

//get - sciaganie wartosci z listy (input: pozycja i Header)
int get_val(node* &H, int x)
{
	//sprawdzanie liczby elementow w liscie
	node* p = H;
	node* s = H;
	int l_el = 0;

	while (p != NULL)
	{
		l_el = l_el + 1;
		p = p->next;
	}
	p = H;

	if (x > l_el)
	{
		cout << "BLAD";
		return -1;
	}

	else
	{
		for (int i = 1; i < x; i++)
		{
			p = p->next;
		}
		return p->val;
	}
	

}

//set - ustawianie wartosci z listy o podanym indeksie
void set_val(node* &H, int x, int pos)
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

//sortowanie babelkowe (bool okresla czy rosnaco - 1 czy malejaco - 0) TODO: wskazniki tez skacza wiec dac p blizej i ewentualnie guarda
void bubble_sort(node* &H, bool by)
{
	int l_el = 0;
	node* p = H;
	int j = 0;

	while (p!=NULL)
	{
		p = p->next;
		l_el = l_el + 1;
	}
	p = H;

	
	for (int i = j = 0; j < l_el - 1; j++)
	{
		for (int i = 1; i < l_el; i++)
		{
		//	cout << "Wartosc p: " << p->val << endl;
		//	cout << "Porownanie: ";
			//cout << p->val << " " << p->next->val << endl;
			//show(H);
			//cout << endl;
			if (p->val > p->next->val)
			{
				swapPrev(H, i);
			}
			//cout << endl;
			p = p->next;
		}

		p = H;
	}
	
	

}

//zamiana z poprzednikiem -> caly node
void swapPrev2(node* &H, int pos)
{

	node* p = H;
	node* tmp;
	int l_el=0;

	while (p != NULL)
	{
		p = p->next;
		l_el = l_el + 1;
	}
	p = H;
	//sprawdzanie czy pos wykracza poza zakres
	if (pos > l_el )
	{
		return;
	}
	
	else if(pos==1)
	{

		node* b = H;
		node* s;
		node* del;
		//guard
		add(H, 0);
		b = H;
		s = b->next->next;
		tmp = b->next;
		b->next = s;
		tmp->next = tmp->next->next;
		s->next = tmp;
		del = H;
		H = H->next;
		delete del;

	}

	else 
	{
		node* b=H;
		node* s;
		//znajdowanie elementu 
		for (int i = 1; i <= pos-3; i++)
		{
			b = b->next;
		}
		
		s = b->next->next;
		tmp = b->next;
		b->next = s;
		tmp->next = tmp->next->next;
		s->next = tmp;

	
		
	}
}