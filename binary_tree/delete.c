#include <stdio.h>
#include <malloc.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};
 
/* newNode() allocates a new node with the given data and NULL left and 
   right pointers. */
struct node* newNode(int data)
{
  // Allocate memory for new node 
  struct node* node = (struct node*)malloc(sizeof(struct node));
 
  // Assign data to this node
  node->data = data;
 
  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
		
	}
}

void moveup(struct node *root,struct node *parent)
{
	if(root)
	{
		printf("%d* ",root->data);
		moveup(root->left,root);
		if(parent)
		{
		if(root->left!=NULL)
		root->right=parent->right;
		else
		
		printf("%d@ ",root->data);
		}
	}
}

int delete(struct node *root,int data,struct node *parent,struct node **rootref)
{
	int rv=0;
	if(root)
	{
		if(root->data == data)
		{
			if(parent)
			{
				
				if(parent->left != NULL && parent->left->data == data)
				{
					if(root->left != NULL)
					parent->left = root->left;
					else
                                        parent->left = root->right;
				}
				else
				{
					if(root->left != NULL)
					parent->right = root->left;
					else
					parent->right = root->right;
				}
			}
			else
			{
				if(root->left)
				*rootref = root->left;
				else
				*rootref = root->right;
			}
			printf("%d#",root->data);
			moveup(root,NULL);	
			rv=1;
		}
		else
		{
			printf("%d#",root->data);
			rv = delete(root->left,data,root,&root);
			if(rv == 1)
				return 1;
			rv = delete(root->right,data,root,&root);
		}
	}

	return rv;
}
 
 
int main()
{
  /*create root*/
  struct node *root = newNode(1);  
  int i;
  /* following is the tree after above statement 
 
        1
      /   \
     NULL  NULL  
  */
   
 
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->right->right       = newNode(5);
  root->right->left       = newNode(6);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
 
 
  root->left->left  = newNode(4);
  root->left->left->right  = newNode(8);
  root->left->left->right->left  = newNode(9);
  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/

  inorder(root); 
  i=delete(root,4,NULL,&root);

  printf("\n\r found %d",i);
  inorder(root);
  //i=delete(root,3,NULL);

  //printf("\n\r found %d",i);
  //inorder(root);
  return 0;
}
