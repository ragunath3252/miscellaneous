#include <stdio.h>
#include <malloc.h>

#define false 0
#define true 1

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

int isbst(struct node *root)
{
        if(root)
        {
                isbst(root->left);
		if(root->left)
		{
			if(root->data < root->left->data)
			{
				return false;
			}	
		}
                isbst(root->right);

        }
	return true;
}
 
 
int main()
{
  /*create root*/
  struct node *root = newNode(3);  
  /* following is the tree after above statement 
 
        1
      /   \
     NULL  NULL  
  */
   
 
  root->left        = newNode(2);
  root->right       = newNode(6);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
 
 
  root->left->left  = newNode(1);
  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/
 root->left->right  = newNode(4);

  inorder(root); 
  if(isbst(root) == false)
	printf("not a bst");
  else
	printf("is a bst");
  return 0;
}
