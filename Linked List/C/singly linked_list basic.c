/* It includes basic operation of insertion and deletion  */


#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	
}node;

/*struct node* intializer()
{
	node *head = NULL; 
	return head;
}*/

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

void insert_end(node **head,int data)
{
	node *new_node,*trav;
	new_node = (node *)malloc(sizeof(node));
	
	if(*head == NULL)
	{
		insert_begin(head,data);   //case of insert at  the begin
	}
	else
	{
		trav = *head;
    	while(trav->next != NULL)
    	{
    		trav = trav->next;
		}
		
		node *new_node = NULL;
		new_node = (node *)malloc(sizeof(node));
		
		new_node->data = data;
		new_node->next = NULL;
		trav->next = new_node;
	}	
}

void insert_after(node **head , int data , int pos )
{
	if(*head == NULL)
	{
		printf("List is already empty...wrong case of insert after\n");
	}
	else
	{
		if(pos <= 0 || pos > len_ll(*head) )
			printf("wrong pos entered\n");
		else
		{
			
			node *trav = *head;
			int i = 0;
			while(i < pos-1)
			{
				trav = trav->next;
				i++;
			}
			if(trav->next == NULL)
			{
				insert_end(head , data);           //case of insert at the end
			}
			else
			{
				node *new_node = (node *)malloc(sizeof(node));
				new_node->data = data;
				new_node->next = trav->next;
				trav->next = new_node;
			}
		}
	}
}

void insert_before(node **head , int data , int pos )
{
	if(*head == NULL)
	{
		printf("List is already empty...wrong case of insert before\n");
	}
	else
	{
		if(pos <= 0 || pos > len_ll(*head) )
			printf("wrong pos entered\n");
		else
		{	
			if(pos == 1)
				insert_begin(head,data);   //case of insert at the begin
			else
			{
				int i = 0;
				node *trav = *head;
				while(i < pos-1)
				{
					trav = trav->next;
					i++;
				}
				node *new_node = (node *)malloc(sizeof(node));
				new_node->data = data;
				new_node->next = trav->next;
				trav->next = new_node; 
			}
		}
	}
}

void del_begin(node **head)
{
	if(*head == NULL)
		printf("Already no element present\n");
	else
	{
		node *trav = *head;
		if(trav->next == NULL)
			*head = NULL;
		else
			*head = (*head)->next;
		free(trav);
	}
}

void del_end(node **head)
{
	if(*head == NULL)
		printf("Already no element present..nothing to delete\n");
	else
	{
		node *trav = *head, *save = NULL;
		while(trav->next != NULL)
		{
			save = trav;
			trav = trav->next;
		}
		if(save == NULL)
		{
			*head = NULL;
			free(trav);
		}
		else
		{
			save->next = NULL;
			free(trav);
		}
	}
}

void del_pos(node **head,int pos)
{
	if(pos <=0 || pos > len_ll(*head))
		printf("wrong pos entered\n");
	else
	{
		if(pos == 1)
			del_begin(head);   //case of delete begin
		else
		{
			node *trav = *head,*save = NULL;
			int i = 0;
			while(i < pos-1)
			{
				save = trav;
				trav = trav->next;
				i++;
			}
			if(trav->next == NULL)
				save->next =NULL;
			else
				save->next = trav->next;
			free(trav);	
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
	node *ll1 ;
	//ll1 = intializer();
	ll1 = NULL;
	

	insert_begin(&ll1,3);
	insert_end(&ll1,4);
	insert_after(&ll1,5,2);   //insert_after(&ll,data,pos);
	insert_before(&ll1,2,1);  //insert_before(&ll,data,pos);
	
	int l = len_ll(ll1);
	printf("length of a linked_list is %d\n", l);
	print_ll(ll1);
	
	del_begin(&ll1);
	del_end(&ll1);
	del_pos(&ll1,1);         //del_pos(&ll,pos);

	printf("linkedlist after deletion is\n");
	print_ll(ll1);
	
	return 0;
}
