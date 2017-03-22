/*DFS using Adjacency list in Undirected graph */
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
				if(trav->data != data)
				{
					Node *new_node = add_node(data);
					new_node->next = save->next;
					save->next = new_node;
				}
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

typedef struct stack
{
	int top;
	int *ar;
}stack;

void push(stack *s, int data)
{
	s->top++;
	s->ar[s->top] = data;
}
void pop(stack *s)
{
	s->top--;
}

void dfs_call(Graph *graph, int source, bool *visited, int size)
{
	stack s;
	s.top = -1;
	
	s.ar = (int *)malloc(size * sizeof(int));
	
	push(&s, source);
	visited[source] = true;
	printf("%d\t", source);
	
	while(s.top != -1)
	{
		int x = s.ar[s.top];
		Node *trav = graph->ar[x];
		int c = 0;
		
		while(trav != NULL)
		{
			if(visited[trav->data] != true)
			{
				c = 1;
				push(&s, trav->data);
				visited[trav->data] = true;
				printf("%d\t", trav->data);
				break;
			}
			trav = trav->next;
		}
		
		if(c != 1)
			pop(&s);
	}
} 

void dfs(Graph *graph, int v)
{
	bool visited[v];
	/*Initializing whole array with false*/
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
		
	int source;
	source = 2;         /*source can be changed according to requirement and should be less than or v*/
	
	dfs_call(graph, source, visited, v);
}

void print_list(Graph *graph, int v)
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
	int v = 4;
	Graph *graph = create_graph(v);
	
	/*Any manual entry i.e. 1, 2 can be before 1, 0  and even no redundancy*/
	sorted_add_edge(graph, 0, 1);
	sorted_add_edge(graph, 0, 2);
	sorted_add_edge(graph, 1, 2);
	sorted_add_edge(graph, 2, 0);    
	sorted_add_edge(graph, 2, 3); 
	sorted_add_edge(graph, 3, 3);
	
	printf("Graph is-->\n");
	print_list(graph, v);
	
	printf("\nDFS traversal is--> ");
	dfs(graph, v);
	
	return 0;
} 
