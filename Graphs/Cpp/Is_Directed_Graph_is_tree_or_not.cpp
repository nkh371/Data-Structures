/*Assume Graph to be directed*/

/*A Graph will be tree, when
1. No cycle is there 
2. All nodes are connected(not strongly connected), but child have only one parent, see below in main()*/

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
}

bool DFS(Graph *g, bool visited[], int s)
{
	int mystack[g->v];         //can't use stack library, coz can't traversable, but i hv to traverse it
	int top = 0;
	bool ans = false;
	
	mystack[top] = s;
	visited[s] = true;
	
	while(top >= 0)
	{
		int val = mystack[top];
		int c = 0;
		
		list<int>::iterator it;
		for(it = g->adj[val].begin(); it != g->adj[val].end(); it++)
		{
			int i;
			for(i = 0; i <= top; i++)
			{
				if(mystack[i] == *it)
				{
					ans = true;
					break;
				}
			}
			
			if(!visited[i])
			{
				c = 1;
				visited[i] = true;
				mystack[++top] = *it;
			}
		}
		
		if(!c)
			top--;
	}
	return ans;
	
}

void Istree(Graph *g)
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
		
	bool ans = false;
	
	ans = DFS(g, visited, 0);
	
	if(ans == true)
		printf("false\n");
	else
	{
		for(i = 0; i < g->v; i++)
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
	//add_edge(g,  0, 0);
	add_edge(g,  0, 1);
	add_edge(g,  1, 2);
	add_edge(g,  2, 3);
	add_edge(g,  4, 3);    //3 has two parents, i.e. wrong 
	//add_edge(g,  4, 1);
	
	print_list(g);
	
	Istree(g);
	
	return 0;
}

