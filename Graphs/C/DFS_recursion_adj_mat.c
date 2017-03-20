/*DFS with recursion using Adjacency Matrix in Undirected Graph*/
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
	graph->ar[v1][v2] = graph->ar[v2][v1] = true;   /* if Graph is directed, then graph->ar[v1][v2] = true */
}

void dfs_call(Graph *graph, int source, bool *visited)
{
	printf("%d\t", source);
	visited[source] = true;
	
	size_t size = sizeof(visited) / sizeof(bool);
	
	int i;
	for(i = 0; i < size; i++)
		if(graph->ar[source][i] == true)
			if(visited[i] != true)
				dfs_call(graph, i, visited);
}

void dfs(Graph *graph, int v)
{
	bool visited[v];
	/*Initializing whole array with false*/
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
		
	int source;
	source = 2;         /*source can be changed according to requirement and should be less than or v*/
	
	dfs_call(graph, source, visited);
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

int main(void)
{
	int v = 4;
	
	Graph *graph = create_graph(v);
	
	add_edge(graph, 0, 1); 
	add_edge(graph, 0, 2); 
	add_edge(graph, 1, 2); 
	add_edge(graph, 2, 0);
	add_edge(graph, 2, 3);  
	add_edge(graph, 3, 3);  
	
	print_matrix(graph, v);
	
	printf("\nDFS traversal is-->");
	dfs(graph, v);
	
	return 0;
}
