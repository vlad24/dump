#include <stdio.h>
#include <string.h>
#include "lists28.h"

List* createList()
{
	List* list = new List ;
	list->first = NULL;
	return list;
}
bool listIsEmpty(List* list)
{
	return (list->first == NULL) ;
}
int elementsLeft(List* list) 
{
	int amount = 0 ;
	ListElement* check = NULL;
	if (!listIsEmpty(list))
	{
		ListElement* tmp = list->first->next ;
		while(tmp != check)
		{
			tmp = tmp->next ;
			amount ++ ;
		}
		amount++;
		return amount ;
	}
	else
		return 0;
}
void printList(List* list) 
{
	int n = elementsLeft(list);
	ListElement* tmp = list->first ;
	for(int j = 1 ; j <= n ; j++)
	{
		printf("%s ",tmp->value) ;
		printf("%d ",tmp->value2) ;
		tmp = tmp->next ;
	}

}
void remove(List* list ,int i)
{
	if (!(listIsEmpty(list)))
	{
		if (!(i == 1))
		{
			ListElement* tmp = list->first ;
			for(int j = 1 ; j < i-1 ; j++)
			{
				if (!(tmp == NULL))
					tmp = tmp->next ;
			}
			if (tmp != NULL)
			{
				if (tmp->next != NULL)
				{
					ListElement* tmp2 = tmp->next ;
					tmp->next = tmp->next->next ;
					delete tmp2;
				}
	
			}
		}
		else
		{
			ListElement* tmp = list->first;
			list->first = list->first->next;
			delete tmp;
		}
	}
}
bool stringsEquals(char* s1, char* s2)
{
	int j = 0;
	bool b = true;
	while((s1[j] != '\0') && (s2[j]!='\0') && b)
	{
		if (!(s1[j] == s2[j]))
			b = false;
		j++;
	}
	return b;
}
bool stringExsists(List* list , char* s)
{
	int n = elementsLeft(list);
	bool g = false;
	int i = 1;
	ListElement* tmp = list->first;
	if (!(listIsEmpty(list)))
	{
		while((i <= n))
		{
			if (!stringsEquals(tmp->value,s))
			{
				tmp = tmp->next;
				i++;
			}
			else
			{
				g = true;
				break;
			}
		}
	}
	return g;
}
ListElement* search(List* list , char* s)
{
	int n = elementsLeft(list);
	int i = 1;
	ListElement* temp = NULL;
	ListElement* tmp = list->first;
	if (!(listIsEmpty(list)))
	{
		while(i <= n)
		{
			if(!stringsEquals(tmp->value,s))
			{
				tmp = tmp->next;
				++i;
			}
			else
			{
				temp = tmp;
				break;
			}
		}
	}
	return temp;
}
void add(List* list , char* s )
{
	int i = elementsLeft(list);	
	if (i >= 1)
		{
			ListElement* tmp = list->first ;
			for (int k = 1 ; k < i ; k++)
			{
				if (tmp->next != NULL)
					tmp = tmp->next ;
			}
				ListElement* tmp2 = tmp->next ;
				tmp->next = new ListElement ;
				
				tmp->next->value = strdup(s);
				tmp->next->value2 = 1 ;
				tmp->next->next = tmp2 ;
			
				
		}
	else
		{
			ListElement* tmp = list->first;
			list->first = new ListElement;
			list->first->next = tmp;
			list->first->value = strdup(s);
			list->first->value2 = 1;
		}
	}

void destroyList(List* list)
{
	int amount = elementsLeft(list);
	if (list->first != NULL)
	{
		ListElement* tmp = list->first;
		for(int i = 1 ; i < amount ; i++)
		{
			ListElement* tmp2 = tmp ;
			tmp = tmp->next ;
			delete tmp2->value;
			delete tmp2;
		}
		delete tmp ;
	}
	delete list ;
}
