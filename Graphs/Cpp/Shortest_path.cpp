/*Assume Graph to be Directed Graph*/
#include <stdio.h>
#include <iostream>
#include <list>
#include <malloc.h>
#include <climits>
#include <stack>
#include <queue>

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

void BFS_fn(Graph *g, int s, bool visited[], int edgeto[])
{
	 queue<int> q;
	 q.push(s);
	 visited[s] = true;
	 
	 while(!q.empty())
	 {
		 int val = q.front();
		 q.pop();
		 
		 list<int>::iterator it;
		 it = g->adj[val].begin();
		 
		 while(it != g->adj[val].end())
		 {
			 if(visited[*it] != true)
			 {
				 edgeto[*it] = s;
				 visited[*it] = true;
				 q.push(*it);
			 }
			 it++;
		 }
	 }
}

void BFS(Graph *g, int s, int edgeto[])
{
	bool visited[g->v];
	
	int i;
	for(i = 0; i < g->v; i++)
		visited[i] = false;
		
	BFS_fn(g, s, visited, edgeto);
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
		
	if(check == INT_MAX)
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
	
	BFS(g, 0, edgeto);     //Accordingly Do BFS taking source as m for better results eg. in case of (5,4), here it gives Not found, but in actual it exist 
	
	/*for(i = 0; i < v; i++)
		printf("%d ", edgeto[i]);*/
	
	int m = 0, n = 4;   //Assuming edge from m to n
	check_exist(edgeto, m, n);
	
	int a = 5, b = 4;
	printf("\n\nWrong Answer--->");   
	check_exist(edgeto, a, b); /*Giving NO, hv to run BFS with source 5*/
	
	BFS(g, a, edgeto);          // have to do BFS on a
	printf("\n\nRight Answer--->");   
	check_exist(edgeto, a, b);
	
	return 0;
}

