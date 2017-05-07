/*Assuming Graph to be Directed Graph*/
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
}

void Reverse_graph(Graph *g1, Graph *g)
{
	int i;	
	for(i = 0; i < g1->v; i++)
	{
		list<int>::iterator it;
		it = g->adj[i].begin();
		
		while(it != g->adj[i].end())
		{
			
			g1->adj[*it].push_back(i);
			it++;
		}
	} 
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

int main(void)
{
	int v = 5;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 2, 3);
	
	print_list(g, v);
	
	printf("Reverse of a Graph is\n\n");
	
	Graph *g1 = create_graph(v);
	Reverse_graph(g1, g);
	
	print_list(g1, v);
	
	return 0;
}
