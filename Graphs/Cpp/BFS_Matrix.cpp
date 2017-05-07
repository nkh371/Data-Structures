#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <queue>

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

void BFS_fn(Graph *g, int s, bool visited[], int v)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	printf("%d ", s);
	
	while(!q.empty())
	{
		int val = q.front();
		q.pop();
		
		int i = 0;
		while(i < v)
		{
			if(visited[i] == false && g->adj[val][i])
			{
				printf("%d ", i);
				visited[i] = true;
				q.push(i);
			}
			i++;
		} 
	}
}

void BFS(Graph *g, int s, int v)
{
	bool visited[v];
	
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
	
	BFS_fn(g, s, visited, v);
}

int main(void)
{
	int v = 5;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 0, 3);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 2, 3);
	
	print_array(g, v);
	
	printf("\nBFS is--> ");
	int source = 0;
	BFS(g, source, v);
	
		
	return 0;
}

