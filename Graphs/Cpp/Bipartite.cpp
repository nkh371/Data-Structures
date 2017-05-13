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

/*Coloring is done*/ 
/*No two Adjacenct have same color*/
/*Red--> 1   Black--> -1  Nocolor--> 0*/ 

bool ans = true;   /*Just making it global for solving sake, use it as private, otherwise anyone  can change it*/

void DFS(Graph *g, int s, bool visited[], int color[])
{
	if(ans == false)
		return;
	
	list<int>::iterator it;
	
	for(it = g->adj[s].begin(); it != g->adj[s].end(); it++)
	{
		if(!visited[*it])
		{
			visited[*it] = true;
			if(color[s] == 1)
				color[*it] = -1;
			else
				color[*it] = 1;
			DFS(g, *it, visited, color);
		}
		else
		{
			if(color[*it] == color[s])
			{
				ans = false;
				return;
			}
		}
	}
}

void isbipartite(Graph *g)
{
	bool visited[g->v];
	int color[g->v];

	int i;
	for(i = 0; i < g->v; i++)
	{
		visited[i] = false;
		color[i] = 0;
	}
	
	/*If Graph is connected*/
	
	color[0] = 1;  /*Assigning red to node 0*/
	DFS(g, 0, visited, color);
	
	/*Checking again that Graph is connected or not, so visited[0 to g->]  all true*/
	for(i = 0; i < g->v; i++)
		if(visited[i] == false)
		{
			ans = false;
			break;
		}
	
	if(ans == true)
		printf("\nYes! given graph is bipartite");
	else
		printf("\nNo! given graph is not bipartite");
}	

int main(void)
{
	int v = 8;    /*v = 7, then connected graph*/
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 0, 2);
	add_edge(g, 0, 5);
	add_edge(g, 0, 6);
	add_edge(g, 1, 3);
	add_edge(g, 2, 3);
	add_edge(g, 2, 4);
	add_edge(g, 4, 5);
	add_edge(g, 4, 6);	
	
	print_list(g, v);
	
	isbipartite(g);
		
	return 0;
}
