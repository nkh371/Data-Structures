#include <stdio.h>
#include <stdlib.h>

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

void preorder(node *head)
{
	if(head == NULL)
		return;
	printf("%d\t",head->data);
	preorder(head->left);
	preorder(head->right);
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
	
	printf("preorder is-->  ");
	preorder(tree);
  
	return 0;
}
