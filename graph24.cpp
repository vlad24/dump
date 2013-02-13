#include "graph24.h"
#include <stdio.h>

Graph* createGraphFromFile(FILE* file)
{
	
	Graph* graph = new Graph;

	char str[20] = {}; 
	int vertexAmount = 0;
	int edgeAmount = 0;
	// Finding out the size
	fscanf(file,"%d ",&vertexAmount);
	fscanf(file,"%d ",&edgeAmount);
	graph->verteces = vertexAmount;

	graph->adjMatrix = new int*[vertexAmount + 1];
	for(int i = 0 ; i <= vertexAmount ; i++)
		graph->adjMatrix[i] = new int[vertexAmount + 1];
	// Initialization
	for(int m = 0 ; m <= vertexAmount ; m++)
		for(int n = 0 ; n <= vertexAmount; n++)
			graph->adjMatrix[m][n] = 0;
	// Filling
	int i = 0;
	int j = 0;
	int value = -2;
	while(!feof(file))
	{
		for(int u = 0 ; u < 3 ; u++)
		{
			fscanf(file,"%d ",&i);
			fscanf(file,"%d ",&j);
			fscanf(file,"%d ",&value);
			graph->adjMatrix[i][j] = value;
			graph->adjMatrix[j][i] = value;
		}
	}
	
	return graph ;
}

void printGraphAdjecencyMatrix(Graph* graph)
{
	printf("Adjecency Matrix of the graph :\n");
	for(int i = 1 ; i <= graph->verteces ; i++)
		for(int j = 1 ; j <= graph->verteces ; j++)
			if( j != graph->verteces)
				printf("%d " , graph->adjMatrix[i][j]);
			else
				printf("%d\n" , graph->adjMatrix[i][j]);
	printf("------------------------ \n");
}

void destroyGraph(Graph* &graph)
{
	for(int i = 0 ; i <= graph->verteces ; i++)
			delete[] graph->adjMatrix[i];
	delete[] graph->adjMatrix;
	delete graph;
}


int findMinUnvisitedVertex(Graph* &graph, int* &dist , bool* &visited)
{
	int min = 2147483647;
	int num = 0;
	for(int j = 1 ; j <= graph->verteces; j++)
	{
		if ((dist[j] < min) && (!(visited[j])))
		{
			min = dist[j];
			num = j;
		}
	}
	return num;
}
	
bool AllVisited(Graph* graph,bool* visited)
{
	bool b = false;
	for(int i = 1 ; i <= graph->verteces; i++)
	{
		b = visited[i];
		if (!b) 
			break;
	}
	return b;
}

bool areNeighbours(Graph* graph , int vertex1, int vertex2)
{
	return (graph->adjMatrix[vertex1][vertex2] != 0);
}

int* dijkstraAlgorythm(Graph* graph , int vertex , int*& sequence)
{
	int* distance = new int[graph->verteces + 1];
	int* neighbours = new int[graph->verteces + 1] ;
	bool* visited = new bool[graph->verteces + 1] ;
	int tmpVertex = vertex;
	int q = 0;

	for (int u = 0 ; u <= graph->verteces ; u++)
			if(u != vertex)
				distance[u] = 2147483647;
			else
				distance[u] = 0;
	for (int u = 0 ; u <= graph->verteces ; u++)
		visited[u] = false;
    
	do
	{
		tmpVertex = findMinUnvisitedVertex(graph,distance,visited);
		
		//printf("%d" , tmpVertex);
		q++;
		sequence[q] = tmpVertex;
		
		for(int neighbour = 1 ; neighbour <= graph->verteces ; neighbour++)
		{
			if (areNeighbours(graph,tmpVertex,neighbour))
				if (!(visited[neighbour]))
					if (graph->adjMatrix[tmpVertex][neighbour] + distance[tmpVertex] <	distance[neighbour] ) 
						distance[neighbour] = graph->adjMatrix[tmpVertex][neighbour] + distance[tmpVertex] ;

		
		}
		visited[tmpVertex] = true;
	}
	while (!(AllVisited(graph,visited)));
	delete[] neighbours;
	delete[] visited;
		
	return distance;
	//return seq;
}

bool lastLeft(Graph* graph,int i , bool* visited)
{
	bool b = true;
	for(int u = 1 ; u <= graph->verteces ; u++)
	{
		if (u != i)
			b = b && visited[u];
	}

	return b && !visited[i];

}

void goDeepRec(int i,Graph* graph,bool* &visited)
{
	
	for (int j = 1 ; j <= graph->verteces ; j++)
		if((graph->adjMatrix[i][j] != 0) && (!visited[j]))
		{
			printf("%d_" , i);
			visited[i] = true;
			goDeepRec(j,graph,visited);
		}
		else
		{
			if (lastLeft(graph,i,visited))
			{
				printf("%d_",i);
				visited[i] = true;
				return;
			}
				
		}
	return;
}
void goInDepthRecoursive(Graph* graph)
{
	bool* visited = new bool[graph->verteces + 1];
	for(int u = 0 ; u <= graph->verteces ; u++)
		visited[u] = false;
	goDeepRec(1,graph,visited);
}

