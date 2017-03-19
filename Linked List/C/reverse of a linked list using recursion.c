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

void reverse_recursive(node **head)
{
	node *first,*second;
	if(*head == NULL)              //neccesary in case if there is empty list
		return;
	first = *head;
	second = first->next;
	if(second == NULL)
		return ;
	reverse_recursive(&second);               //address of the second node is passed i.e. call by reference
	first->next->next = first;
	first->next = NULL;
	*head = second;                /*tricky step*/  //second always remains fixed as last node
}

void print_ll(node *head)
{
	if(head == NULL)
		printf("no element present\n");
	else
	{	
		printf("elements are-->  ");
		while(head != NULL)
		{
			printf("%d\t",head->data);
			head = head->next;
		}
		printf("\n");
	}
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
	
	reverse_recursive(&ll1);

	printf("after reversing\n");
	print_ll(ll1);
	
	return 0;
}
