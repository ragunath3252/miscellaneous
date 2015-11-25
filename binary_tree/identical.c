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

int identical(struct node *root,struct node *dummy)
{	int rv;
	if(root != NULL && dummy != NULL)
	{
		printf("###");
		rv =identical(root->left,dummy->left);
		if(rv == -1)
			return -1;
		if(root->data != dummy->data)	
			return -1;
		rv =identical(root->right,dummy->right);
		if(rv == -1)
                        return -1;
		
	}
	else if (root != NULL && dummy == NULL)
		return -1;
	else if (root == NULL && dummy != NULL)
		return -1;
	else
		return 0;
}
 
 
int main()
{
  /*create root*/
  struct node *root = newNode(1);  
  struct node *dummy;
  dummy=root;
  /* following is the tree after above statement 
 
        1
      /   \
     NULL  NULL  
  */
   
 
  root->left        = newNode(2);
  root->right       = newNode(3);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
 
 
  root->left->left  = newNode(4);
  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/

  if(identical(root,dummy) == 0)
	printf("ientical");
  else
	printf("diff"); 
  return 0;
}
