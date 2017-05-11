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
		head = new_node(data);
	else
	{
		Tree *trav = head;
		while(trav->left != NULL && trav->right != NULL)
		{
			if(data <= trav->data)
				trav = trav->left;
			else
				trav = trav->right;
		}
		if(data <= trav->data)
			trav->left = new_node(data);
		else
			trav->right = new_node(data);
	}
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
	
	inorder(t1);
	
	return 0;
}
