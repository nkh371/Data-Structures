/*Assume Graph to be Directed Graph*/ 

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
	//g->adj[n].push_back(m);  
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

void Find_Degree(Graph *g)
{
	int in[g->v], out[g->v];
	int i;
	
	for(i = 0; i < g->v; i++)
		in[i] = 0;
	
	for(i = 0; i < g->v; i++)
	{
		list<int>::iterator it;
		it = g->adj[i].begin();
		
		out[i] = g->adj[i].size();
		
		while(it != g->adj[i].end())
		{
			in[*it]++;
			it++;
		}
	}
	
	printf("\nNode   In  Out Tot\n");
	for(i = 0; i < g->v; i++)
	{
		printf("%d       %d   %d   %d\n", i, in[i], out[i], in[i] + out[i]);
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
	
	/*code for yourself below, can't manipulate graph, can use it only*/
	
	Find_Degree(g); //Complexity of finding indegree is O(v * oudegree(v)) and outdegree is found by using size()
	
	return 0;
}
