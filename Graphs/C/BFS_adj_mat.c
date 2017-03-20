/*BFS using Adjacency Matrix in Undirected Graph*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph
{
	int v;
	bool **ar;

}Graph;

Graph* create_graph(int v)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->v = v;
	graph->ar = (bool **)malloc(v * sizeof(int*));
	
	int i, j;
	for(i = 0; i < v; i++)
		graph->ar[i] = (bool *)malloc(v * sizeof(int));
	
	/*Initializing graph whole 2D-Array with false*/
	for(i = 0; i < v; i++)
		for(j = 0; j < v; j++)
			graph->ar[i][j] = false;
	
	return graph;
}

void add_edge(Graph *graph, int v1, int v2)
{
	graph->ar[v1][v2] = graph->ar[v2][v1] = true;   /* if Graph is directed, then graph->ar[v1][v2] = true */
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
	*head = trav->next;
	free(trav);
}

void bfs(Graph *graph, int v)
{
	bool visited[v];
	/*Initializing whole array with false*/
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
		
	int source;
	source = 4;         /*source can be changed according to requirement*/
	
	queue *q = NULL;
	enqueue(&q, source);
	visited[source] = true;
	
	while(q != NULL)
	{
		int x = q->data;
		printf("%d\t",x);
		dequeue(&q);                        /*directly can't use trav->data, because it will be dequeued here, so no info left,leads to segmentation fault*/
		
		int i;
		for(i = 0; i < v; i++)
		{
			if(visited[i] != true)
			{
				if(graph->ar[x][i] == true)
				{
					enqueue(&q, i);
					visited[i] = true;
				}
			}
		}
		
	}	
}

void print_matrix(Graph *graph, size_t size)
{
	printf("2D Matrix is-->\n");
	
	int i,j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			printf("%d\t", graph->ar[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	int v = 5;
	
	Graph *graph = create_graph(v);
	
	add_edge(graph, 0, 1); 
	add_edge(graph, 1, 2); 
	add_edge(graph, 2, 3); 
	add_edge(graph, 3, 4);
	add_edge(graph, 4, 0);  
	
	print_matrix(graph, v);
	
	printf("\nBFS traversal is-->");
	bfs(graph, v);
	
	return 0;
}
