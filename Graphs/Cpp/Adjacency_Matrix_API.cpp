#include <stdio.h>
#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct Graph
{
	int v;
	bool **adj;
}Graph;

Graph* create_graph(int v)
{
	Graph *g = (Graph *)malloc(sizeof(Graph));
	
	g->v = v;
	g->adj = (bool **)malloc(v * sizeof(bool *));
	
	int i;
	for(i = 0; i < v; i++)
		g->adj[i] = (bool *)malloc(v * sizeof(bool));
		
	return g;
}

void add_edge(Graph *g, int m, int n)
{
	g->adj[m][n] = true;
	if(m != n)                    //(2,2) should not be added twice
	    g->adj[n][m] = true;
}

void print_array(Graph *g, int v)
{
	int i, j;
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < v; j++)
			printf("%d ", g->adj[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int v = 5;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 2, 3);
	
	print_array(g, v);
	
	return 0;
}
