/*Assume Graph to be Undirected graph*/
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
	if(n != m)
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

bool ans = false;   /*Just making it global for solving sake, use it as private, otherwise anyone  can change it*/

bool DFS(Graph *g, bool visited[], int parent, int s)
{
	visited[s] = true;
	
	list<int>::iterator it;
	
	for(it = g->adj[s].begin(); it != g->adj[s].end(); it++)
	{
		if(!visited[*it])
		{
			DFS(g, visited, s, *it);
		}
		else
		{
			if(parent != *it)
			{
				ans = true;
			}
		}
	}
	return ans;
}

void Iscycle(Graph *g)
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
			
	bool ans;		
			
	for(i = 0; i < g->v; i++)
	{
		if(!visited[i])
		{	
			int parent = -1;
			ans = DFS(g, visited, parent, i);
			if(ans == true)
				break;
		}
	}
	
	if(ans == true)
		printf("Cyclic\n");
	else
		printf("Acyclic\n");
}

int main(void)
{
	int v = 4;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 2, 3);

	print_list(g, v);
	
	Iscycle(g);

	return 0;
}
