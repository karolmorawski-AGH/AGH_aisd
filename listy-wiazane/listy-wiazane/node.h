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
void rm(node *& H);
void rmVal(node* &H, int x);
void remove(node* &H);
void divide_list(node* &H, int x);
//int get_val(node* &H, int x);
int get_val(node * H, int x);
void set_val(node* &H, int x, int pos);
void bubble_sort(node* &H, bool by);
void swapPrev2(node* &H, int pos);
void swapPos(node *& head, int pos1, int pos2);
void ordered_insert(node *&H, int x);
void insertion_sort(node* &H, bool by);
void selection_sort(node * &H);
void addFirst(node *&H, node *& p);
void merge_sort(node*& H);
node * merge_master(node*& H);
node * merge_split(node* H);
node * merge_merge(node  *H, node  *right);
//-------------------------------------//
int partition(node * H, int l, int r);
void quickSortRecursion(node * H, int l, int r);
void addBeforeFirst(node *& head, int value);
int get_val(node * head, int position);
void quickSort(node *& head);