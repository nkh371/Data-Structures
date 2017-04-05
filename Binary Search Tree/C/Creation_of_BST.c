#include <stdio.h>
#include <malloc.h>

typedef struct tree
{
	int data;
	struct tree *left, *right;

}tree;

tree* newNode(int data)
{
	tree *nw = NULL;
	
	nw = (tree *)malloc(sizeof(tree));
	nw->data = data;
	nw->left = nw->right = NULL;
	
	return nw;
}

void createNode(tree **root, int data)
{
	if(*root == NULL)
		*root = newNode(data);
	else
	{
		tree *trav = *root;
		
		while(trav->left != NULL && trav->right != NULL)
		{
			if(data <= trav->data)
				trav = trav->left;
			else
				trav = trav->right;
		}
		if(data <= trav->data)
			trav->left = newNode(data);
		else
			trav->right = newNode(data);
	}
}
void inorder(tree *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}
 
int main(void)
{
	tree *t1 = NULL;
	createNode(&t1, 20);
	createNode(&t1, 15);
	createNode(&t1, 25);
	createNode(&t1, 12);
	createNode(&t1, 18);
	createNode(&t1, 22);
	createNode(&t1, 28);
	
	inorder(t1);
	
	return 0;
}
