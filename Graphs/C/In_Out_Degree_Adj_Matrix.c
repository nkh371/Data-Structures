/*Indegree and Outdegree using Adjacency Matrix in Directed Graph*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph
{
	int v;
	bool **ar;

}Graph;

Graph* create_graph(int v)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->v = v;
	graph->ar = (bool **)malloc(v * sizeof(int*));
	
	int i, j;
	for(i = 0; i < v; i++)
		graph->ar[i] = (bool *)malloc(v * sizeof(int));
	
	/*Initializing graph whole 2D-Array with false*/
	for(i = 0; i < v; i++)
		for(j = 0; j < v; j++)
			graph->ar[i][j] = false;
	
	return graph;
}

void add_edge(Graph *graph, int v1, int v2)
{
	graph->ar[v1][v2] = true;
}

void print_matrix(Graph *graph, size_t size)
{
	printf("2D Matrix is-->\n");
	
	int i,j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%d\t", graph->ar[i][j]);
		}
		printf("\n");
	}
}

void in_out_degree(Graph *graph, int v)     /*if graph is undirected either count indegree or outdegree as total degree*/
{
	printf("\nNode\t Indegree\t Outdegree\n");
	int i, j;
	int in, out;
	for(i = 0; i < v; i++)
	{
		in  = out = 0; 
		for(j = 0; j < v; j++)
		{
			in += graph->ar[j][i];
			out += graph->ar[i][j];
		}
		printf("%d\t    %d\t\t     %d\n", i, in, out);
	}
}

int main(void)
{
	int v = 6;
	Graph *graph = create_graph(v);
	
	add_edge(graph, 0, 1); /*way is going from 0 to 1*/
	add_edge(graph, 1, 2); 
	add_edge(graph, 2, 3); 
	add_edge(graph, 3, 4);
	add_edge(graph, 4, 5);
	add_edge(graph, 2, 5);
	add_edge(graph, 5, 2);  
	
	print_matrix(graph, v);
	
	in_out_degree(graph, v);
	
	return 0;
}
