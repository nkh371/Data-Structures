
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

int lin_search(node *head,int key)
{
	int i = 0;
	while(head != NULL)
	{
		if(head->data == key)
			return i;
		head = head->next;
		i++;
	}
	return -1;
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
	
	int ans = lin_search(ll1,6);    //lin_search(ll1,key);
	
	if(ans == -1)
		printf("element not present\n");
	else
		printf("element present and is at %d index\n",ans+1);
	return 0;
}
