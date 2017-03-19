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

bool search(node *head,int key)
{
	while(head->left != NULL ||head->right != NULL)
	{
		if(key == head->data)
			return true;
		else if(key <= head->data)
			head = head->left;
		else
			head = head->right;
	}
	return false;
}

void inorder(node *head)
{
	if(head == NULL)
		return;
	inorder(head->left);
	printf("%d\t",head->data);
	inorder(head->right);
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
	
	inorder(tree);
	
	int key;
	printf("\nenter key-->");
	scanf("%d",&key);
	bool x = search(tree,key);
	if(x == true)
		printf("item found\n");
	else
		printf("item not found\n");
		
	return 0;
}
