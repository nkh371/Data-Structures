#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;

}node;

node * newNode(int data)
{
	node *new_node = NULL;
	new_node = (node *)malloc(sizeof(node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;	
	return new_node;
}

void create(node **head,int n)
{
	node *trav = *head;
	if(*head == NULL)
	{
		*head = newNode(n);
		return;
	}
	
	if(n <= trav->data)
		create(&trav->left,n);
	else
		create(&trav->right,n);
}

typedef struct queue
{
	node *save;
	struct queue *ptr;

}queue; 

void enqueue(queue **head,node *root)
{
	queue *new_node = (queue *)malloc(sizeof(queue));
	new_node->save = root;
	if(*head == NULL)
	{
		new_node->ptr = NULL;
		*head = new_node;
	}
	else
	{
		queue *trav = *head;
		while(trav->ptr != NULL)
			trav = trav->ptr;
		new_node->ptr = NULL;
		trav->ptr = new_node;
	}
}

void dequeue(queue **head)
{
	queue *trav = *head;
	if(trav->ptr == NULL)
		*head = NULL;
	else
		*head = (*head)->ptr;
	free(trav);
}


void levelorder(node *root)
{
	queue *head = NULL;
	enqueue(&head,root);
	
	while(head != NULL)
	{
		queue *trav = head;
		printf("%d\t",trav->save->data);
		if(trav->save->left != NULL)
			enqueue(&head,trav->save->left);
		if(trav->save->right != NULL)
			enqueue(&head,trav->save->right);
		dequeue(&head);
	}		
}

int main()
{
	node *tree = NULL;
	create(&tree,20);
	create(&tree,15);
	create(&tree,25);
	create(&tree,12);
	create(&tree,18);
	create(&tree,22);
    create(&tree,28);
	
	printf("levelorder is-->  ");
	levelorder(tree);
		
	return 0;
}
