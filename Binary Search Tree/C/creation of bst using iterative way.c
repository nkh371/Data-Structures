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
	node *new_node = newNode(n);
	
	if(*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		node *trav = *head;
		while(1)
		{
			if(n <= trav->data)
			{
				if(trav->left == NULL)
				{
					trav->left = new_node;
					break;
				}
				else
					trav = trav->left;
			}
			else
			{
				if(trav->right == NULL)
				{
					trav->right = new_node;
					break;
				}
				else
					trav = trav->right;
			}
		}
	}
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
	
  return 0;
  
}
