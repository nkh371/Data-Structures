/* asc_sort is sorted by finding first length of the linkedlist */

#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	
}node;

int len_ll(node *head)
{
	int i;
	i = 0;
	
	while(head != NULL)
	{
		i++;
		head = head->next;
	}
	
	return i;
}

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

void asc_sort(node **head)
{
	int l = len_ll(*head);
	int i,j;
	
	node *ptr = *head , *ptr2;
	
	for( i = 0 ; i < l-1 ; i++)
	{
		ptr = *head;
		for( j = 0 ; j < l-1-i ; j++)
		{
			ptr2 = ptr->next;
			if(ptr->data > ptr2->data)
			{
				int temp = ptr->data;
				ptr->data = ptr2->data;
				ptr2->data = temp; 
			}
			ptr = ptr->next;
		}	
	} 
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
	insert_begin(&ll1,6);
	insert_begin(&ll1,5);
	
	print_ll(ll1);
	
	asc_sort(&ll1);             

	printf("after asc_sorting\n");     
	print_ll(ll1);

	return 0;
}
