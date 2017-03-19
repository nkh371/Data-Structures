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

/*two stacks are being formed*/
node *ar[100]; //Assuming max. elements would be 100
int top = -1;  // top of the stack1
node *ar2[100]; 
int top2 = -1;// top of the stack2

/*similar to preorder traversal,the only difference is
1.root->left is first being pushed on the stack
2.instead of printing root info,we just pushed it onto other stack
Then finally we print the 2nd stack elements*/

void postorder(node *root)
{
	ar[++top] = root;
	while(top >= 0)
	{
		ar2[++top2] = ar[top];
		top--;
		if(ar2[top2]->left != NULL)
			ar[++top] = ar2[top2]->left;
		if(ar2[top2]->right != NULL)
			ar[++top] = ar2[top2]->right;
	}
	while(top2 >= 0)
	{
		printf("%d\t",ar2[top2]->data);
		top2--;
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
	create(&tree,13);
	
	postorder(tree);
	
	return 0;

}
