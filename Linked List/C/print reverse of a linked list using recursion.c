#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	
}node;

void insert_begin(node **head,int data)
{ 
	node *new_node;
	new_node = (node *)malloc(sizeof(node));
	
	if(*head == NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		*head = new_node;	
	}	
	else
	{
		new_node->data = data;
		new_node->next = *head;
		*head = new_node;
	}
}

void print_ll(node *head)
{
	if(head == NULL)
		return;
	printf("%d\t",head->data);
	print_ll(head->next);
}

void print_reverse_ll(node *head)
{
	if(head == NULL)
		return ;
	print_reverse_ll(head->next);
	printf("%d\t",head->data);
}

int main(void)
{
	node *ll1 = NULL;
	insert_begin(&ll1,3);
	insert_begin(&ll1,4);
	insert_begin(&ll1,61);
	insert_begin(&ll1,5);
	insert_begin(&ll1,51);
	
	print_ll(ll1);
	
	printf("reverse form is--> ");
	print_reverse_ll(ll1);
	
	return 0;
}
