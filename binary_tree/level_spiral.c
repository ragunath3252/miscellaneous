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

int max (int a,int b)
{
        if(a > b)
                return a;
        else
                return b;
}

int height(struct node *root)
{
        if(root)
        {
                return 1+max(height(root->left),height(root->right));
        }
        return 0;
}


void printlevel(struct node *root,int h,int order)
{
	if(root)
	{
		if(h == 0)
			printf("%d ",root->data);

		else
		{
			if(order % 2 == 1)
			{
				printlevel(root->left,h-1,order);
				printlevel(root->right,h-1,order);
			}
			else
			{
				printlevel(root->right,h-1,order);
                        	printlevel(root->left,h-1,order);
			}
		}
	}
}

void level(struct node *root)
{
	int i;
	int h=height(root);
	printf("\n\r h is %d",h);
	for(i=0;i<=h;i++)
		printlevel(root,i,i);
	
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
 
 
int main()
{
  /*create root*/
  struct node *root = newNode(1);  
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

  root->left->right  = newNode(5);

  root->right->left  = newNode(6);
  root->right->right  = newNode(7);
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
  level(root);
  return 0;
}
