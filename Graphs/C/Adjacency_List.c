/*adjacency list in Undirected graph */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;

}Node;

typedef struct Graph
{
	int v;
	Node **ar;

}Graph;

Graph* create_graph(int v)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	
	graph->v = v;
	graph->ar = (Node **)malloc(v * sizeof(Node *));
	
	/*Initializing each ar element with NULL*/
	int i;
	for(i = 0; i < v; i++)
		graph->ar[i] = NULL;
	
	return graph;
}

Node* add_node(int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	
	return new_node;
}

void add_edge(Graph *graph, int v1, int v2)
{
	if(graph->ar[v1] == NULL)
	{
		graph->ar[v1] = add_node(v2);
	}
	else
	{
		Node *nw = add_node(v2);
		nw->next = graph->ar[v1];
		graph->ar[v1]= nw;
	}
	
	/*Skip below part if graph is directed*/
	if(graph->ar[v2] == NULL)
	{
		graph->ar[v2] = add_node(v1);
	}
	else
	{
		Node *nw = add_node(v1);
		nw->next = graph->ar[v2];
		graph->ar[v2]= nw;
	}
}

void print_matrix(Graph *graph, int v)
{
	int i;
	for(i = 0; i < v; i++)
	{
		Node *trav = graph->ar[i];
		printf("list %d--> ", i);
		
		if(trav == NULL)
			printf("empty");
		else
		{
			while(trav != NULL)
			{
				printf("%d\t",trav->data);
				trav = trav->next;
			}
		}
		printf("\n");
	}
}

int main(void)
{
	int v = 6;
	Graph *graph = create_graph(v);
	
	add_edge(graph, 0, 1); 
	add_edge(graph, 1, 2); 
	add_edge(graph, 2, 3); 
	add_edge(graph, 3, 4);
	add_edge(graph, 4, 0);  
	/* node 5 has no links */
	print_matrix(graph, v);
	
	return 0;
}
