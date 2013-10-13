#include "hashTables.h"
#include "lists28.h"
#include <stdlib.h>

HashTable* createHashTable()
{
	int size = 4211;
	HashTable* hTable = new HashTable;
	hTable->hArray = new List*[size];
	for(int i = 0; i < size; i++)
	{
		(hTable->hArray)[i] = createList();
	}
	return hTable;
}
int hashFunction(char string[])
{
	int p1 = 31;
	int pPow = 1;
	int j = 0;
	int sum = 0;
	while(string[j] != '\0')
	{
		sum += abs(((int(string[j]) * pPow) % 4211));
		pPow *= p1;
		j++;
	}
	return (sum % 4211);
}

void addToHashTable(HashTable* hTable, char string[])
{
	int index = hashFunction(string);
	if (listIsEmpty(hTable->hArray[index]))
	{
		add( hTable->hArray[index] , string );
	}
		
	else if (stringExsists(hTable->hArray[index],string))
		(search(hTable->hArray[index],string))->value2 ++ ;
		else 
			add( hTable->hArray[index] , string );

}
void destroyHashTable(HashTable* &hTable)
{
	for (int i = 0; i < 4211; i++)
		destroyList((hTable->hArray)[i]);
	delete [] hTable->hArray;
	delete hTable;
}
