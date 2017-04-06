#include <stdio.h>
#include <malloc.h>
#include <stack>

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

void postorder(tree *root)
{
	if(root == NULL)
		return ;
	
	stack<tree*> stack1;

	do
	{
		while(root != NULL)
		{
			if(root->right != NULL)
				stack1.push(root->right);
			stack1.push(root);
			root = root->left;
		}
		root = stack1.top();
		stack1.pop();
		
		// include this if condition, coz if stack == empty, then stack1.top() gives segmentation fault 
		if(stack1.empty())
			break;
		
		
		if(root->right != NULL && root->right == stack1.top())
		{
			stack1.pop();
			stack1.push(root);
			root = root->right;
		}
		else
		{
			printf("%d ", root->data);
			root = NULL;
		}
	} while(!stack1.empty());
	/*last element print here coz stack is empty and loop breaks*/
	printf("%d", root->data);
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
	
	postorder(t1);
	
	return 0;
}

