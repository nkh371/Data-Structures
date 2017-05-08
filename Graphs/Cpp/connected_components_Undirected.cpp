/*Assume Graph to be undirected*/
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

void DFS_fn(Graph *g, int s, bool visited[], int cc[], int c)
{
	visited[s] = true;
	cc[s] = c;
	
	list<int>::iterator it;
	for(it = g->adj[s].begin(); it != g->adj[s].end(); it++)
	{
		if(!visited[*it])
			DFS_fn(g, *it, visited, cc, c);
	}
}

void Connected(Graph *g)
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
	
	int cc[g->v];
	int c = 0;
	
	for(i = 0; i < g->v; i++)
	{
		if(!visited[i])
		{
			DFS_fn(g, i, visited, cc, c);
			c++;
		}
	}
	
	int max = 0;
	for(i = 0; i < g->v; i++)
	{	
		if(max < cc[i])
			max = cc[i];
	}
	
	int ar[max +1];
	
	for(i = 0; i < max + 1; i++)
		ar[i] = 0;
		
	for(i = 0; i < g->v; i++)
	{	
		ar[cc[i]]++;
	}
	
	int max_length = 0;
	
	for(i = 0; i < max + 1; i++)
	{	
		if(max_length < ar[i])
			max_length = ar[i];
	}
	
	printf("\n\nNo. of components is--> %d", max + 1);   // max + 1, coz start from 0.
	printf("\nLargest component is of length--> %d", max_length);
	 
}

int main(void)
{
	int v = 10;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 0, 9);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 4, 5);
	add_edge(g, 6, 7);
	add_edge(g, 6, 8);
	add_edge(g, 7, 8);
	
	print_list(g, v);
	
	Connected(g);
	
	return 0;
}
