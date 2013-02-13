// Lists with strings for hash tables
#pragma once
struct ListElement
{
	char* value ;
	int value2 ;
	ListElement* next ;
};
struct List
{
	ListElement* first ;
};
List* createList();
bool listIsEmpty(List* list);
int elementsLeft(List* list);
void printList(List* list);
void remove(List* list ,int j);
void add(List* list , char* s );
void destroyList(List* list);

bool stringExsists(List* list , char* s);
ListElement* search(List* list, char* s);