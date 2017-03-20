/*BFS using Adjacency list in Undirected graph */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
	/*Initializing each Node with NULL*/
	int i;
	for(i = 0; i < v; i++)
	{
		graph->ar[i] = NULL;
	}
	
	return graph;
} 

Node* add_node(int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;
	
	return new_node;
}

void insertion_sorted(Graph *graph, int v, int data)
{
	/*Insertion at the sorted order*/
	if(graph->ar[v] == NULL)
	{
		graph->ar[v] = add_node(data);
	}
	else
	{
		Node *trav = graph->ar[v], *save = NULL;
		while(trav != NULL)
		{
			if(trav->data < data)
			{
				save = trav;
				trav = trav->next;
			}
			else
				break;
		}
		if(save == NULL)
		{
			if(trav->data != data)
			{
				Node *new_node = add_node(data);
				new_node->next = graph->ar[v];
				graph->ar[v] = new_node;
			}
		}
		else
		{
			if(trav == NULL)
			{
				Node *new_node = add_node(data);
				save->next = new_node;
			}
			else
			{
				Node *new_node = add_node(data);
				new_node->next = save->next;
				save->next = new_node;
			}
		}
	}
}

void sorted_add_edge(Graph *graph, int v1, int v2)
{
	insertion_sorted(graph, v1, v2);
	/*Skip the below part if graph is directed*/
	insertion_sorted(graph, v2, v1);
}

typedef struct queue
{
	int data;
	struct queue *next;

}queue;

void enqueue(queue **head, int data)
{
	queue *new_node = (queue *)malloc(sizeof(queue));
	new_node->data = data;
	new_node->next = NULL;
	if(*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		queue *trav = *head;
		while(trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = new_node;
	}
}

void dequeue(queue **head)
{
	queue *trav = *head;
	*head = (*head)->next;
	free(trav);
}

void bfs(Graph *graph, int v)
{
	int source = 4;  /*can be changed according to requirement or can be taken as i/p from user*/
	bool visited[v];
	
	/*Initializing each with false*/
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
	
	queue *q = NULL;
	enqueue(&q, source);
	visited[source] = true;
	
	while(q != NULL)
	{
		int x = q->data;
		printf("%d\t", x);
		dequeue(&q);
		Node *trav = graph->ar[x];
		while(trav != NULL)
		{
			if(visited[trav->data] != true)
			{
				enqueue(&q, trav->data);
				visited[trav->data] = true;
			}
			trav = trav->next;
		}
	}

}

void print_list(Graph *graph,int v)
{
	int i;
	for(i = 0; i < v; i++)
	{
		printf("list %d--> ", i);
		Node *trav = graph->ar[i];
		if(trav == NULL)
			printf("Empty");
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
	
	/*Any manual entry i.e. 1, 2 can be before 1, 0  and even no redundancy*/
	sorted_add_edge(graph, 0, 1);
	sorted_add_edge(graph, 1, 2);
	sorted_add_edge(graph, 1, 0);
	sorted_add_edge(graph, 1, 0);    
	sorted_add_edge(graph, 2, 3); 
	sorted_add_edge(graph, 3, 4);
	sorted_add_edge(graph, 4, 0);
	
	printf("Graph is-->\n");
	print_list(graph, v);
	
	printf("\nBFS traversal is--> ");
	bfs(graph, v);
	
	return 0;
} 

