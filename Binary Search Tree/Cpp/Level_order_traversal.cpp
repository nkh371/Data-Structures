#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <queue>

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

void levelorder(Tree *root)
{
	queue<Tree *> myq;
	myq.push(root);
	
	while(!myq.empty())
	{
		Tree *trav = myq.front();
		printf("%d ", trav->data);
		myq.pop();
		
		if(trav->left != NULL)
			myq.push(trav->left);
		
		if(trav->right != NULL)
			myq.push(trav->right);
	}	
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
	
	levelorder(t1);
	
	return 0;
}
