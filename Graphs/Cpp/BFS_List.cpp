#include <stdio.h>
#include <iostream>
#include <list>
#include <queue>
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

void BFS_fn(Graph *g, int s, bool visited[])
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	printf("%d ", s);
	
	while(!q.empty())
	{
		int val = q.front();
		q.pop();
		
		list<int>::iterator it;
		it = g->adj[val].begin();
		
		while(it != g->adj[val].end())
		{
			if(visited[*it] == false)
			{
				printf("%d ", *it);
				visited[*it] = true;
				q.push(*it);
			}
			it++;
		} 
	}
}

void BFS(Graph *g, int s, int v)
{
	bool visited[v];
	
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
	
	BFS_fn(g, s, visited);
}

int main(void)
{
	int v = 5;
	Graph *g = create_graph(v);
	add_edge(g, 0, 1);
	add_edge(g, 0, 3);
	add_edge(g, 1, 2);
	add_edge(g, 1, 3);
	add_edge(g, 2, 3);
	
	print_list(g, v);
	
	printf("\nBFS is--> ");
	int source = 0;
	BFS(g, source, v);
	
	return 0;
}
