#pragma once
#include <stdio.h>

struct Block
{
	int intValue;
	char* stringValue;
};
struct Graph
{
	int edges;
	int verteces;
	int** adjMatrix;
	int** incidMatrix;
};


Graph* createGraphFromFile(FILE* file);
void goInDepthRecoursive(Graph* graph);
void destroyGraph(Graph* &graph);
void printGraphAdjecencyMatrix(Graph* graph);
int* dijkstraAlgorythm(Graph* graph , int vertex, int*& sequence);


