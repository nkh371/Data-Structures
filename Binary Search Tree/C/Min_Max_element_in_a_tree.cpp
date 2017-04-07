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

tree* createNode(tree *root, int data)
{
	if(root == NULL)
		return newNode(data);
	if(data <= root->data)
		root->left = createNode(root->left, data);
	else
		root->right = createNode(root->right, data);
	return root;
}

int min(tree *root)
{
	if(root == NULL)
		throw "no root present";
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int max(tree *root)
{
	if(root == NULL)
		throw "no root present";
	while(root->right != NULL)
	{
		root = root->right;
	}
	return root->data;
}

int main(void)
{
	tree *t1 = NULL;
	t1 = createNode(t1, 20);
	createNode(t1, 15);
	createNode(t1, 20);
	createNode(t1, 25);
	createNode(t1, 12);
	createNode(t1, 18);
	createNode(t1, 22);
	createNode(t1, 28);
	createNode(t1, 13);

	try
	{	
		printf("Min. element is--> %d\n", min(t1));
	}
	catch(const char *s)
	{
		printf("%s", s);
	}
	try
	{	
		printf("Max. element is--> %d\n", max(t1));
	}
	catch(const char *s)
	{
		printf("\n%s", s);
	}
	
	return 0;
}
