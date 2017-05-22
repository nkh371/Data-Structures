/*Assuming both 'v' and 'u' are present in a tree*/

#include <iostream>
#include <stdio.h>
#include <malloc.h>

using namespace std;

typedef struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
}Tree;

Tree *new_node(int data)
{
	Tree *nw = (Tree *)malloc(sizeof(Tree));
	nw->data = data;
	nw->left = nw->right = NULL;
	
	return nw;
}

Tree* add_edge(Tree *head, int data)
{
	if(head == NULL)
		return new_node(data);
	if(data <= head->data)
		head->left = add_edge(head->left, data);
	else
		head->right = add_edge(head->right, data);
	
	return head;
}	

void inorder(Tree *root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

Tree* LCARecursive(Tree *root, int v, int u)
{
	if(root == NULL)
		return NULL;
	else if(root->data < v && root->data < u)
		return LCARecursive(root->right, v, u);
	else if(root->data > v && root->data > u)
		return LCARecursive(root->left, v, u);
	
	return root;
}

Tree* LCA(Tree *root, int v, int u)
{
	while(root != NULL)
	{
		if(root->data < v && root->data < u)
			root = root->right;
		else if(root->data > v && root->data > u)
			root = root->left;
		else
			break;
	}
	return root;
}

int main(void)
{
	Tree *t1 = NULL;
	t1 = add_edge(t1, 20);
	add_edge(t1, 15);
	add_edge(t1, 25);
	add_edge(t1, 12);
	add_edge(t1, 18);
	add_edge(t1, 22);
	add_edge(t1, 28);
	add_edge(t1, 19);
	
	
	inorder(t1);
	
	int v = 18, u = 12;
	Tree *ans = LCARecursive(t1, v, u);
	printf("\nLCA of %d and %d is--> %d", v, u, ans->data);
	
	v = 18, u = 19;
	ans = LCA(t1, v, u);
	printf("\n\nLCA of %d and %d is--> %d", v, u, ans->data);
	
	return 0;
}
