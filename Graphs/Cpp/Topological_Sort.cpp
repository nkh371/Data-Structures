/*Assume graph to be Directed*/
/*Topological Sort is used by OS, to schedule the tasks, which depends on other*/
#include <stdio.h>
#include <iostream>
#include <list>
#include <malloc.h>
#include <stack>

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

stack<int> mystack;
void DFS_fn(Graph *g, int s, bool visited[])
{
	visited[s] = true;
	
	list<int>::iterator it;
	for(it = g->adj[s].begin(); it != g->adj[s].end(); it++)
		if(!visited[*it])
			DFS_fn(g, *it, visited);
	
	mystack.push(s);
}

void DFS(Graph *g)
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
	
	for(i = 0; i < g->v; i++)
		if(!visited[i])
			DFS_fn(g, i, visited);
			
	printf("Order of execution is--> ");
	
	int size = mystack.size();
	//printf("%d ", size); 
	
	for(i = 0; i < size; i++)
	{
		printf("%d ", mystack.top());
		mystack.pop();
	}
}
	
int main(void)
{
	int v = 7;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 0, 5);
	add_edge(g, 0, 2);
	add_edge(g, 1, 4);
	add_edge(g, 3, 2);
	add_edge(g, 3, 4);
	add_edge(g, 3, 5);
	add_edge(g, 3, 6);
	add_edge(g, 5, 2);
	add_edge(g, 6, 0);
	add_edge(g, 6, 4);
	
	print_list(g, v);
	
	DFS(g);
	
	return 0;
}
