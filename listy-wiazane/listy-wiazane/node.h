#pragma once

struct node
{
	int val;
	node* next;
	node* prev;
};
void show(node* H);
void add(node* &H, int x);
void readFile(char *filen, node *&H);
void swapPrev(node* &H, int x);
int swapNext(node* &H, int x);
void insert(node* &H, int x, int pos);
void rm(node* &H, int x);
void rmVal(node* &H, int x);
void remove(node* &H);
void divide_list(node* &H, int x);
int get_val(node* &H, int x);
void set_val(node* &H, int x, int pos);
void bubble_sort(node* &H, bool by);
void swapPrev2(node* &H, int pos);