#include <stdio.h>
#include <malloc.h>
#include <stack>

using namespace std;

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
	else if(data <= (*root)->data)
		createNode(&(*root)->left, data);
	else
		createNode(&(*root)->right, data);
}

void inorder(tree *root)
{
	if(root == NULL)
		return;
		
	stack<tree *> mystack;
	mystack.push(root);
	while(!mystack.empty())
	{
		if(root->left != NULL)
		{
			mystack.push(root->left);
			root = root->left;
			continue;
		}
		root = mystack.top();
		printf("%d ", root->data);
		mystack.pop();
		
		if(root->right != NULL)
		{
			mystack.push(root->right);
			root = root->right;
			continue;
		}
	}
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
	createNode(&t1, 13);
	createNode(&t1, 14);
	
	inorder(t1);
	
	return 0;
}
