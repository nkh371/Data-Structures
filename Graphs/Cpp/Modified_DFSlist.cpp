#include <stdio.h>
#include <iostream>
#include <list>
#include <malloc.h>

using namespace std;

typedef struct Graph
{
	int v;
	list<int> *adj;
}Graph;

Graph* create_graph(int v)
{
	Graph *g = (Graph *)malloc(sizeof(Graph));
	
	g->v = v;
	g->adj = new list<int>[v] ;
	
	return g;
}

void add_edge(Graph *g, int m, int n)
{
	g->adj[m].push_back(n);
	g->adj[n].push_back(m);
}

void print_list(Graph *g, int v)
{
	int i;
	for(i = 0; i < v; i++)
	{
		printf("Node %d--> ", i);
		if(g->adj[i].empty())
			printf("NULL");
		else
		{
			list<int>::iterator it;
			for(it = g->adj[i].begin(); it != g->adj[i].end(); it++)
			{
				printf("%d ", *it);
			}
		}
		printf("\n");
	}
}

void DFS_fn(Graph *g, int s, bool visited[])
{
	printf("%d ", s);
	visited[s] = true;
	
	list<int>::iterator it;
	it = g->adj[s].begin();
	while(it != g->adj[s].end())
	{
		if(visited[*it] == false)
			DFS_fn(g, *it, visited);
		it++;
	}
}

void Modified_DFS(Graph *g, int v)
{
	bool visited[v];
	
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
	
	for(i = 0; i < v; i++)
	{
		if(visited[i] == false)
			DFS_fn(g, i, visited);   // i  is Source here. 
	}
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
	
	print_list(g, v);
	
	printf("\nModified DFS is--> ");
	Modified_DFS(g, v);   //To reach node 4 as well, who has no edge with anyone.
 	
	return 0;
}

