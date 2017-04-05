#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

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
 
bool search(tree *root, int key)
{
	if(root == NULL)
		return false;
	if(root->data == key)
			return true;
	else if(key < root->data)
		return search(root->left, key);
	else
		return search(root->right, key);
			
	return false;
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
	
	inorder(t1);
	
	int key;
	printf("\n\nenter key-->");
	scanf("%d", &key);
	
	bool b = search(t1, key);
	
	if(b == true)
		printf("\n%d is present\n", key);
	else
		printf("\n%d is not present\n", key);
	
	return 0;
}
