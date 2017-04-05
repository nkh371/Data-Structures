#include <stdio.h>
#include <malloc.h>
#include <queue>

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

void levelorder(tree *root)
{
	queue<tree *> q;
	q.push(root);
	while(!q.empty())
	{
		tree *temp = q.front();
		printf("%d ", temp->data);
		
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
		
		q.pop();
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
	
	levelorder(t1);
	
	return 0;
}
