#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	
}tree;

tree* add_node(int data)
{
	tree *new_node = (tree *)malloc(sizeof(tree));
	new_node->data = data;
	new_node->left = new_node->right = NULL;
	return new_node;
}

void create(tree **root, int data)
{
	if(*root == NULL)
	{
		*root = add_node(data);
	}
	else
	{
		tree *trav = *root;
		while(1)
		{
			if(data <= trav->data)
			{
				if(trav->left == NULL)
				{
					trav->left = add_node(data);
					break;
				}
				else
					trav = trav->left;
			}
			else
			{
				if(trav->right == NULL)
				{
					trav->right = add_node(data);
					break;
				}
				else
					trav = trav->right;
			}
		}
	}
}

int find_min(tree *root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	return root->data;
}

int main(void)
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    tree *obj = NULL;
	create(&obj, 50);
	create(&obj, 30);
	create(&obj, 70);
	create(&obj, 40);
	create(&obj, 20);
	create(&obj, 80);
	create(&obj, 60);
    
    int min = find_min(obj);
    printf("Minimum element is--> %d", min);
 
    return 0;
}
