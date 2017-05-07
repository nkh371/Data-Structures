/*Assume Graph to be Directed Graph*/
#include <stdio.h>
#include <iostream>
#include <list>
#include <malloc.h>
#include <climits>
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

void DFS_fn(Graph *g, int s, bool visited[], int edgeto[])
{
	 visited[s] = true;
	 
	 list<int>::iterator it;
	 it = g->adj[s].begin();
	 
	 while(it != g->adj[s].end())
	 {
		 if(visited[*it] != true)
		 {
			 edgeto[*it] = s;
			 DFS_fn(g, *it, visited, edgeto);
		 }
		 it++;
	 }
}

void DFS(Graph *g, int s, int edgeto[])
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
		
	DFS_fn(g, s, visited, edgeto);
}

void check_exist(int edgeto[], int m, int n)
{
	int check;
	stack<int> s;
	s.push(n);
	
	do
	{
		check = edgeto[s.top()];
		if(check != INT_MAX)
			s.push(check);
	} while(check != m && check != INT_MAX);
		
	if(s.size() == 1)
		printf("\nNo, Path not Exist b/w %d and %d", m, n);
	else
	{
		printf("\nYes, Path Exist b/w %d and %d and is --> ", m, n);    //We might not get shortest path. For that use BFS.
		while(!s.empty())
		{
			printf("%d ", s.top());
			s.pop();
		}
	}
}

int main(void)
{
	int v = 6;
	Graph *g = create_graph(v);
	add_edge(g, 0, 3);
	add_edge(g, 0, 4);
	add_edge(g, 0, 5);
	add_edge(g, 1, 5);
	add_edge(g, 3, 1);
	add_edge(g, 5, 4);
	
	print_list(g, v);
	
	int edgeto[v];
	int i;
	for(i = 0; i < v; i++)
		edgeto[i] = INT_MAX;
	
	DFS(g, 0, edgeto);
	
	/*for(i = 0; i < v; i++)
		printf("%d ", edgeto[i]);*/
	
	int m = 0, n = 4;   //Assuming edge from m to n
	check_exist(edgeto, m, n);
	
	int a = 0, b = 2;   
	check_exist(edgeto, a, b);
	
	
	return 0;
}
