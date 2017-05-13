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

bool search(Tree *root, int item)
{
	if(root == NULL)
		return false;
	do
	{
		if(root->data == item)
			return true;
		else if(item < root->data)
			root = root->left;
		else
			root = root->right;
	} while(root != NULL);
	
	return false;
}

bool searchRecursion(Tree *root, int item)
{
	if(root == NULL)
		return false;
	if(root->data == item)
		return true;
	
	if(item <= root->data)
		return searchRecursion(root->left, item);
	else
		return searchRecursion(root->right, item);
	
	return false;
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
	
	int item;
	printf("\nEnter item-->");
	scanf("%d", &item);
	
	bool ans = search(t1, item);
	
	if(ans == true)
		printf("Element found\n");
	else
		printf("Element not found\n");
		
	printf("\nEnter item-->");
	scanf("%d", &item);
	
	ans = searchRecursion(t1, item);
	
	if(ans == true)
		printf("Element found\n");
	else
		printf("Element not found\n");
	
	return 0;
}
