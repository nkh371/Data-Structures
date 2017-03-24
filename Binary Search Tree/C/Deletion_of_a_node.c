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

void inorder(tree *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d\t", root->data);
	inorder(root->right);
}

void delete(tree **root, int x)
{
	tree *head = *root;
	tree *trav = NULL, *save = NULL;
	
	/*Searching for node where x is present*/
	while(head != NULL)
	{
		if(head->data == x)
		{
			trav = head;
			break;
		}
		save = head;
		if(x < head->data)
			head = head->left;
		else
			head = head->right;
	}
	/*If x not present*/
	if(trav == NULL)
		printf("%d is not present in the tree\n", x);
	/*If x is present*/
	else
	{
		/*node having one child or no child*/
		if(trav->left == NULL || trav->right == NULL)
		{
			/*node is root itsef*/
			if(save == NULL)
			{
				if(trav->left != NULL)
					*root = trav->left;
				else
					*root = trav->right;
				free(trav);			
			}
			/*node is not root*/
			else
			{
				if(save->left->data == x)
				{
					if(trav->left != NULL)
						save->left = trav->left;
					else
						save->left = trav->right;	
				}
				else
				{
					if(trav->left != NULL)
						save->right = trav->left;
					else
						save->right = trav->right;
				}
				free(trav);
			}
		}
		/*node having two child*/
		else
		{
			save = trav->right;
			tree *save1 = NULL;
			while(save->left != NULL)
			{
				save1 = save; 
				save = save->left;
			}
			trav->data = save->data;
			/*node is root itsef*/
			if(save1 == NULL)
				trav->right = NULL;
			/*node is not root*/
			else
				save1->left = NULL;
			free(save);
		}
	}
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
    
    printf("Inorder traversal of the given tree \n");
    inorder(obj);
 
    printf("\nDelete 20\n");
    delete(&obj, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(obj);
 
    printf("\nDelete 30\n");
    delete(&obj, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(obj);
 
    printf("\nDelete 50\n");
    delete(&obj, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(obj);
 
    return 0;
}
