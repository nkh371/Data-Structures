#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left,*right;

}node;

node *newNode(int data)
{
	node *nw = (node *)malloc(sizeof(node));
	nw->data = data;
	nw->left = nw->right = NULL;
	return nw;
}

void create(node **root,int data)
{
	if(*root == NULL)
	{
		*root = newNode(data);
		return ;
	}
	else
	{
		node *trav = *root;
		if(data <= trav->data)
			create(&trav->left,data);
		else
			create(&trav->right,data);
	}
}

/*stack is being formed*/
node *ar[100]; //Assuming max. elements would be 100
int top = -1;  // top of the stack

void postorder(node *root)
{
	do
	{
		while(root != NULL)
		{
			if(root->right != NULL)
			{
				ar[++top] = root->right;
			}
			ar[++top] = root;
			root = root->left;
		}
		node *trav = ar[top];
		top--;
		if(trav->right != NULL && trav->right == ar[top])
		{
			root = ar[top];
			top--;
			ar[++top] = trav;
		}
		else
		{
			printf("%d\t",trav->data);
		}	
	}while(top >= 0);
}

int main()
{
	node *tree = NULL;
	
	create(&tree,20);
	create(&tree,15);
	create(&tree,25);
	create(&tree,18);
	create(&tree,12);
	create(&tree,22);
	create(&tree,28);
	create(&tree,13);
	
	postorder(tree);
	
	return 0;

}
