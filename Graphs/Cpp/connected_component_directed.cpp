/*Assume Graph to be Directed Graph*/
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

Graph* Reverse(Graph *g)
{
	Graph *g1 = create_graph(g->v);
	
	int i;
	for(i = 0; i < g->v; i++)
	{
		list<int>::iterator it;
		for(it = g->adj[i].begin(); it != g->adj[i].end(); it++)
		{
			g1->adj[*it].push_back(i);
		}
	}
	return g1;
}

stack<int> mystack;

void Post_DFS_fn(Graph *g, int s, bool visited[])
{
	visited[s] = true;
	
	list<int>::iterator it;
	for(it = g->adj[s].begin(); it != g->adj[s].end(); it++)
	{
		if(!visited[*it])
			Post_DFS_fn(g, *it, visited);
	}
	//printf("%d ", s);
	mystack.push(s);
}

void Post_DFS(Graph *g)
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
	
	for(i = 0; i < g->v; i++)
	{
		if(!visited[i])
			Post_DFS_fn(g, i, visited);
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

void DFS(Graph *g)
{
	bool visited[g->v];
	int cc[g->v];
	int c = 0;
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
	
	int size = mystack.size();
	
	for(i = 0; i < size; i++)
	{
		int s = mystack.top();
		if(!visited[s])
		{	
			DFS_fn(g, s, visited, cc, c);
			c++;
		}
		mystack.pop();
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
		//printf("%d ", cc[i]);
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
	int v = 7;
	Graph *g = create_graph(v);
	add_edge(g, 1, 3);
	add_edge(g, 2, 1);
	add_edge(g, 3, 2);
	add_edge(g, 1, 4);
	add_edge(g, 6, 4);
	add_edge(g, 4, 5);
	add_edge(g, 5, 6);
	
	print_list(g, v);
	
	Graph *g1 = Reverse(g);
	
	printf("\nReverse of graph is-->\n");
	print_list(g1, v);
	
	Post_DFS(g1);
	
	/*int i;
	int s = mystack.size();
	for(i = 0; i < s; i++)
	{
		printf("%d ", mystack.top());
		mystack.pop();
	}*/
	
	DFS(g);
	  
	return 0;
}
