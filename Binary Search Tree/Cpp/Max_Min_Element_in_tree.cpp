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

int min(Tree *root)
{
	if(root == NULL)
		throw "Root is NULL\n";
		
	while(root->left != NULL)
	{
		root = root->left;
	}
	
	return root->data;
}

int max(Tree *root)
{
	if(root == NULL)
		throw "Root is NULL\n";
		
	while(root->right != NULL)
	{
		root = root->right;
	}
	
	return root->data;
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
	
	int c = 0;
	
	try
	{
		int mn = min(t1);
		printf("\nMinimum Element is--> %d", mn);
	}
	catch(char const *str)
	{
		c = 1;
		cout << str;
	}
	
	if(c != 1)
	{
		int mx = max(t1);
		printf("\nMinimum Element is--> %d", mx);
	}
	
	return 0;
}
