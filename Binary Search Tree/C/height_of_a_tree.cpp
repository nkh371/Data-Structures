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

void inorder(tree *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}
 
int height(tree *root)
{ 
	if(root == NULL)
		return -1;
	printf("\n");
	int h = -1;
	queue<tree *> q;
	q.push(root);
	while(1)
	{
		int c = q.size();
		if(c == 0)
			break;
		h++;
		while(c > 0)
		{
			root = q.front();
			q.pop();
			//printf("%d ", root->data);
			if(root->left != NULL)
				q.push(root->left);
			if(root->right != NULL)
				q.push(root->right);
			c--;
		}
	}
	return h;
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
	
	inorder(t1);
	
	int h = height(t1);
	printf("\nheight of a tree is %d", h);
	
	return 0;
}
