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

bool DFS(Graph *g, bool visited[], int parent[], int s)
{
	bool ans = false;
	
	int stack[g->v];         //cant use in-built stack, coz can't  traverse it.
	int top = 0;
	
	visited[s] = true;
	stack[top] = s;
	
	while(top >= 0)
	{
		int c = 1;
		int val = stack[top];
		
		list<int>::iterator it;
		for(it = g->adj[val].begin(); it != g->adj[val].end(); it++)
		{
			 int i;
			 for(i = 0; i <= top ; i++)
			 {
				 if(stack[i]  == *it && parent[val] != *it)
				 {
					//printf("%d", parent[s]);
					ans = true;
					break;	  
				 }
			  }
			  
			  if(!visited[*it])
			  {
				  c = 0;
				  parent[*it] = val;
				  visited[*it] = true;
				  stack[++top] = *it;
				  break;
			  }
		  }
		  
		  if(c != 0)
			  top--;
	 }
	return ans;
}

void Iscycle(Graph *g)
{
	bool visited[g->v];
	int parent[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
	{
		visited[i] = false;
		parent[i] = -1;
	}
	
	bool ans = false;
	
	for(i = 0; i < g->v; i++)
	{
		if(!visited[i])
		{	
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
	int v = 9;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 4, 5);
	add_edge(g, 6, 7);
	add_edge(g, 6, 8);
	add_edge(g, 7, 8);
	
	print_list(g, v);
	
	Iscycle(g);

	return 0;
}
