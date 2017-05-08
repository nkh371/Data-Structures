/*Assume Graph to be Directed*/
#include <stdio.h>
#include <iostream>
#include <list>
#include <stack>
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

bool DFS_fn(Graph *g, bool visited[], int s)
{
	int s1[g->v];           //cant use stack inbuilt as it is not traversable using iterator
	int top = 0;
	s1[top] = s;
	visited[s] = true;
	
	int c = 0;
	
	while(top >= 0)
	{
		int val = s1[top];
		
		list<int>::iterator it;
		it = g->adj[val].begin();
		
		while(it != g->adj[val].end())
		{
			int i;
			for(i = 0; i <= top; i++)
				if(s1[i] == *it)
				{
					c = 1;
					break;
				}
			if(visited[*it] != true)
			{
				//printf("%d ", *it); 
				visited[*it] = true;
				s1[++top] = *it;
				break;
			}
			it++;
		}
		
		if(it == g->adj[val].end())
			top--;
	}
	if(c == 1)
		return true;
	else
		return false;
}

void Iscyclic(Graph *g)
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i< g->v; i++)
		visited[i] = false;
	bool ans = false;
	for(i = 0; i < g->v; i++)
	{
		if(visited[i] == false)
		{	
			//printf("%d ", i);
			ans = DFS_fn(g, visited, i);
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
	int v = 6;
	Graph *g = create_graph(v);
	
	add_edge(g, 0, 3);
	//add_edge(g, 2, 2);   //self loop
	add_edge(g, 0, 4);
	add_edge(g, 0, 5);
	add_edge(g, 1, 5);
	add_edge(g, 3, 1);
	add_edge(g, 5, 4);
	
	print_list(g, v);

	Iscyclic(g);
	
	return 0;
}
