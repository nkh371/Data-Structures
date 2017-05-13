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


void preorder(Tree *root)
{
	if(root == NULL)
		return;
	
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Tree *root)
{
	if(root == NULL)
		return;
	
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(Tree *root)
{
	if(root == NULL)
		return;
	
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
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
	
	printf("Preorder--> ");
	preorder(t1);
	
	printf("\nInorder--> ");
	inorder(t1);
	
	printf("\nPostorder--> ");
	postorder(t1);
	
	return 0;
}
