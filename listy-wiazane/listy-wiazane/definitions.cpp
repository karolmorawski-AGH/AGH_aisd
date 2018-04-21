#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <windows.h>
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
	node * tmp = new node;
	tmp->val = x;

	if (H == NULL) {
		H = tmp;
		tmp->next = NULL;

	}
	else {
		tmp->next = H;
		H = tmp;

		tmp->prev = NULL;
		tmp->next->prev = H;
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

//usuwanie elementów
void rm(node *& H)
{

	node * temp = H;
	H = H->next;
	delete temp;

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
		if (p->next)
		{
			p = p->next;
		}
		else
		{
			break;
		}
	}
		
		//ustawianie wartosci
		p->val = temp->val;
		delete temp;
	

}

//sortowanie babelkowe (bool okresla czy rosnaco - 1 czy malejaco - 0) T
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
	
	add(H, -1);
	node* s = H;
	for (int i = 0; i < l_el - 2; i++) //przed ostatnia wartoscia
	{
		p = p->next;
	}
	H = H->next;
	s->next = NULL;
	p->next->next = s;

	p = H;
	for (int j = 0; j < l_el-1; j++)
	{
		for (int i = 0; i < l_el; i++)
		{
			if (p->val > p->next->val)
			{
				swapPrev2(H, i+1);
				p = H;
				for (int k = 0; k < i-1; k++)
				{
					p = p->next;
				}
			}
			p = p->next;
		}
		p = H;
	}
	
	for (int i = 0; i < l_el - 1; i++) //usuwanie guarda
	{
		p = p->next;
	}
	s = p->next;
	p->next = NULL;
	delete s;
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

//zamiana z dowolnym elementem
void swapPos(node *& H, int pos1, int pos2) 
{
	//jesli pos1==pos2
	if (pos1 == pos2) 
	{
		return;
	}

	//algorytm powinien zadzialac tak samo bez wzgledu na kolejnosc
	if (pos1 > pos2) {
		swap(pos1, pos2);
	}
	
	//jesli lista pusta
	if (H == NULL || H->next == NULL) {
		return;
	}

	//more than one element

	int i = 1;
	

	node * temp = H;

	node * pom1 = NULL;
	node * pom2 = NULL;

	while (temp) {
		if (i == pos1) {
			pom1 = temp;
		}

		if (i == pos2) {
			pom2 = temp;
		}

		i++;
		temp = temp->next;
	}

	//nie istnieje jeden lub drugi element;
	if (pom1 == NULL || pom2 == NULL) {
		return;
	}

	//--------------------------------------------------------//
	//nie sa obok siebie
	if (pom1->next != pom2) {
		node * pom2Next = pom2->next;
		node * pom1Prev = pom1->prev;
		node * pom2Prev = pom2->prev;

		if (pom1->prev == NULL) {
			H = pom2;

			pom2->next = pom1->next;
			pom2->prev->next = pom1;
			pom1->next = pom2Next;

			pom1->prev = pom2->prev;

			if (pom1->next != NULL) {
				pom1->next->prev = pom1;
			}

			pom2->prev = pom1Prev;
			pom2->next->prev = pom2;
			return;
		}

		pom1->prev->next = pom2;
		pom2->next = pom1->next;
		pom2->prev->next = pom1;
		pom1->next = pom2Next;

		pom1->prev = pom2->prev;

		if (pom1->next != NULL) {
			pom1->next->prev = pom1;
		}

		pom2->prev = pom1Prev;
		pom2->next->prev = pom2;

		return;
	}

	//obok siebie
	if (pom1->next == pom2) {

		node * pom2Next = pom2->next;

		if (pom1->prev == NULL) {
			H = pom2;

		
			pom2->next = pom1;
			pom1->next = pom2Next;


		
			node * pointerZero = pom2->prev;
			pom2->prev = NULL;
			if (pom1->next == NULL)
				pom1->prev = pom2;
			pom1->next->prev = pointerZero;
			return;
		}

		node * pom1Prev = pom1->prev;


		pom1->prev->next = pom2;
		pom2->next = pom1;
		pom1->next = pom2Next;

		pom2->prev = pom1Prev;
		pom1->prev = pom2;
		if (pom2Next != NULL) {
			pom2Next->prev = pom1;
		}

		return;
	}

	return;
}

//sort while adding elements
void ordered_insert(node *&H, int x)
{
	node * pomocnik = new node;
	pomocnik->val = x;

	//jesli pusta
	if (H == NULL)
	{
		H = pomocnik;
		pomocnik->next = NULL;
		return;
	}

	//element ktory chcemy wstawic mniejszy lub rowny obecnemu
	if (H->val >= x) {
		pomocnik->next = H;
		H = pomocnik;
		return;
	}

	node *tmp = H;

	while (tmp != NULL)
	{
		if (tmp->next == NULL && tmp->val <= x)
		{
			tmp->next = pomocnik;
			pomocnik->next = NULL;
			return;
		}

		if (tmp->val <= x && tmp->next->val >= x)
		{
			pomocnik->next = tmp->next;
			tmp->next = pomocnik;
			return;
		}
		tmp = tmp->next;
	}
}

//insertion sort
void insertion_sort(node* &H, bool by)
{
	if (H == NULL || H->next == NULL)
	{
		return;
	}
	
	//guard
	add(H, 0);
	node* guard = H;
	//pointers to linked list elements which may or may not be swapped if conditions met
	node* p = H->next;
	node* q = p->next;
	//Helps track next positions
	int iterator = 2;
	//current position, input for swapPos()
	int position = iterator;
	//checks if q->val is the same EVERY while loop iteration; if isn't break loop
	int check_val;

	//WHILE LOOP HERE
	while (q!= NULL)
	{
		position = iterator;
		check_val = q->val;
		if (p->val > q->val)
		{
			while (q->val==check_val)
			{
				//self-explanatory
				if (p->val > q->val)
				{
					swapPos(H, position, position + 1);
				}
				//decrementing position because pointers are going to be decremented as well
				position--;
				//if 'p' is on guard
				if (p->prev == NULL)
				{
					break;
				}
				//decrementing 'p' and 'q' positions
				p = p->prev->prev;
				//or if p is actually behind guard
				if (p== NULL)
				{
					break;
				}
				q = p->next;

				/*
				//Check if in fact insertion sort
				Sleep(200);
				system("cls");
				show(H);
				cout << endl;
				*/
				
			}
		
		}
		iterator++;
		p = H;
		q = H;
		//not the fastest but the easiest way to move 'p' and 'q' to next iteration's position
		for (int i = 0; i < iterator; i++)
		{
			q = q->next;
		}
		//if 'q' "happens" to get to the end of linked list
		if (q == NULL)
		{
			break;
		}
		p = q->prev;
	}
	//deleting guard...
	node* DEL = H;
	H = H->next;
	delete DEL;
}