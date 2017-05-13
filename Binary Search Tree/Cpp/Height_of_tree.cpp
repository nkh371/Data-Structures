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

int height(Tree *root)
{
	if(root == NULL)
		return -1;
	
	int h = -1;
	queue<Tree *> myq;
	
	myq.push(root);
	
	while(1)
	{
		int c = myq.size();
		if(c == 0)
			break;
		h++;
		
		while(c > 0)
		{
			Tree *trav = myq.front();
			printf("%d ", trav->data);
			myq.pop();
			if(trav->left != NULL)
				myq.push(trav->left);
			if(trav->right != NULL)
				myq.push(trav->right);
			c--;
		}
		printf("\n");
	}
	
	return h;
}

int heightRecursion(Tree *root)
{
	if(root == NULL)
		return 0;
	return 1 + max(heightRecursion(root->left), heightRecursion(root->right));
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
	add_edge(t1, 19);
	
	
	/*Assuming height = min. no. edges needed to traverse from root to longest leaf node*/
	int h = height(t1);
	printf("\nHeight of a tree(no. of edges) is--> %d", h);
	
	/*Assuming height = min. no. nodes needed to traverse from root to longest leaf node*/
	h = heightRecursion(t1);
	printf("\n\nHeight of a tree(no. of levels i.e through nodes) is--> %d", h);
	
	return 0;
}
