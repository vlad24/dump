#include <stdio.h>
#include "lists28.h"
#include "hashTables.h"

void zeroString(char buffer[],int size)
{
	for(int i = 0 ; i < size ; i++)
			buffer[i] = '\0';
}
int main()
{
	FILE* f1 = fopen("file1.txt","r");
	FILE* f2 = fopen("file2.txt","r");
	char buffer[50] = {};
	HashTable* hTable = createHashTable();
	while(!feof(f1))
	{
		zeroString(buffer,50);
		fgets(buffer,50,f1);
		addToHashTable(hTable,buffer);
	}
	fclose(f1);

	while(!feof(f2))
	{
		zeroString(buffer,50);
		fgets(buffer,524,f2);
		int index = hashFunction(buffer);
		if(stringExsists(hTable->hArray[index],buffer))
			printf("%s\n",buffer);

	}
	fclose(f2);
	destroyHashTable(hTable);
	getc(stdin);
}