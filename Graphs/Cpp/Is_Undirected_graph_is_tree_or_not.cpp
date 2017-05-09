/*Assume Graph to be undirected*/

/*A Graph will be tree, when
1. No cycle is there 
2. All nodes are connected*/

#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

typedef struct
{
	int v;
	list<int> *adj;
}Graph;

Graph* create_graph(int v)
{
	Graph *g = new Graph;
	
	g->v = v;
	g->adj = new list<int>[v];

	return g;
}

void add_edge(Graph *g, int m, int n)
{
	g->adj[m].push_back(n);
	
	if(m != n)
		g->adj[n].push_back(m);
}

bool DFS(Graph *g, bool visited[], int s, int parent[])
{
	bool ans = false;
	
	int mystack[g->v];   //can't use stack library, coz can't traversable, but i hv to traverse it
	int top = 0;

	visited[s] = true;
	mystack[top] = s;
	
	while(top >= 0)
	{
		int count = 0;
		int val = mystack[top];
		
		list<int>:: iterator it;
		for(it = g->adj[val].begin(); it != g->adj[val].end(); it++)
		{
			int i;
			for(i = 0; i <= top; i++)
			{
				if(mystack[i] == *it && parent[val] != *it)
				{
					ans = true;
					break;
				}
			}
			
			if(!visited[*it])
			{
				count = 1;
				parent[*it] = val;
				visited[*it] = true;
				mystack[++top] = *it;
			}
		}
		if(!count)
			top--;
	}
	
	return ans;
} 

void Istree(Graph *g)
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
	ans = DFS(g, visited, 0, parent);
	
	
	if(ans == true)        //cycle exists
		printf("false\n");
	else
	{
		for(i = 0; i < g->v; i++)   // cycle don't exist but if components are not connected, i.e all are not visited
		{
			if(!visited[i])
			{
				ans = true;
				break;
			}
		}
		if(ans == true)
			printf("false\n");
		else
			printf("true\n");
	}
}

void print_list(Graph *g)
{
	int i;
	for(i = 0; i < g->v; i++)
	{
		printf("Node %d--> ", i);
		if(!g->adj[i].size())
			printf("NULL");
		else
		{
			list<int>::iterator it;
			for(it = g->adj[i].begin(); it != g->adj[i].end(); it++)
			{
				printf("%d ",*it);
			} 
		}
		printf("\n");
	}
}

int main(void)
{
	int v = 5;
	Graph *g = create_graph(v);
	add_edge(g,  0, 1);
	add_edge(g,  1, 2);
	add_edge(g,  2, 3);
	add_edge(g,  3, 4);
	add_edge(g,  4, 1);
	
	
	print_list(g);
	
	Istree(g);
	
	return 0;
}
