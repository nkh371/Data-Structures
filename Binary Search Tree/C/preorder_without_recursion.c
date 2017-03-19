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
int top = 0;  // top of the stack

void preorder(node *root)
{
	ar[top] = root;
	while(top >= 0)
	{
		node *trav = ar[top];
		printf("%d\t",trav->data);
		top--;
		if(trav->right != NULL)
		{
			top++;
			ar[top] = trav->right;
		}
		if(trav->left != NULL)
		{
			top++;
			ar[top] = trav->left;
		}
	}
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
	
	preorder(tree);
	
	return 0;

}
