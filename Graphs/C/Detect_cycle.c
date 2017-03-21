/*Detect a cycle in Directed graph*/
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
	Graph *g = (Graph *)malloc(sizeof(Graph));
	g->v = v;
	g->ar = (Node **)malloc(v * sizeof(Node *));
	
	/*Initializing each node with NULL*/
	int i;
	for(i = 0; i < v; i++)
		g->ar[i] = NULL;
	
	return g;
}

Node* add_node(int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void add_edge(Graph *g, int v1, int v2)
{
	Node *save = NULL, *trav = g->ar[v1];
	while(trav != NULL)
	{
		if(trav->data < v2)
		{
			save = trav;
			trav = trav->next;
		}
		else
			break;
	}
	if(save == NULL)
	{
		if(trav == NULL)
		{
			g->ar[v1] = add_node(v2);
		}
		else if(trav->data != v2)
		{
			Node *nw = add_node(v2);
			nw->next = g->ar[v1];
			g->ar[v1] = nw;
		}
	}
	else
	{
		if(trav == NULL)
		{
			save->next = add_node(v2);
		}
		else
		{
			if(trav->data != v2)
			{
				Node *nw = add_node(v2);
				nw->next = save->next;
				save->next = nw;
			}
		}
	}
}
	
void print_list(Graph *g, int v)
{
	int i;
	for(i = 0; i < v; i++)
	{
		printf("list %d is--> ", i);
		Node *trav = g->ar[i];
		if(trav == NULL)
			printf("Empty");
		else
		{
			while(trav != NULL)
			{
				printf("%d\t", trav->data);
				trav = trav->next;
			}
		}
		printf("\n");
	}
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

bool detect_cycle(Graph *g, int source, int v)
{
	bool visited[v];
	
	/*Initializing each with false*/
	int i;
	for(i = 0; i < v; i++)
		visited[i] = false;
	
	stack s;
	s.top = -1;
	s.ar = (int *)malloc(v * sizeof(int));
	
	push(&s, source);
	visited[source] = true;
	
	while(s.top != -1)
	{
		int x = s.ar[s.top];
		int c = 0;
		Node *trav = g->ar[x];
		
		while(trav != NULL)
		{
			int i = 0;
			for(i = 0; i <= s.top; i++)
				if(trav->data == s.ar[i])
					return true;
			if(visited[trav->data] != true)
			{
				c = 1;
				push(&s, trav->data);
				visited[trav->data] = true;
			}
			trav = trav->next;
		}
		
		if(c != 1)
			pop(&s);
	}
	return false;
}

int main(void)
{
	int v = 4;
	Graph *graph = create_graph(v);
	
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 1, 2);
	add_edge(graph, 2, 0);    
	add_edge(graph, 2, 3); 
	add_edge(graph, 3, 3);
	
	printf("Graph is-->\n");
	print_list(graph, v);
	
	int source = 2;
	bool b = detect_cycle(graph , source, v);
	
	if(b == true)
		printf("\nGraph contains cycle\n");
	else
		printf("\nGraph does not contain any cycle\n");
	
	return 0;
}
