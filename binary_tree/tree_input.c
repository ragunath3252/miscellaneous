#include <stdio.h>
#include <malloc.h>
#include "tree.h"

int insert(struct node **root1,int data)
{
	struct node *temp=NULL;
	struct node *root;
	int rv=0;
	
	root = *root1;

	printf("#%d# ",data);

	if(!(*root1))
                {
                        *root1 = (struct node *)malloc(sizeof(struct node));
                        (*root1)->data=data;
			(*root1)->left=NULL;
			(*root1)->right=NULL;
			rv =1;
			printf("assign");
                }
                else if(!(*root1)->left)
                {
			printf("@%d@ ",data);
                        temp = (struct node *)malloc(sizeof(struct node));
                        temp->data=data;
			(temp)->left=NULL;
			(temp)->right=NULL;
			(*root1)->left = temp;
			rv =1;
                }
                else if(!(*root1)->right)
                {
			printf("*%d* ",data);
                        temp = (struct node *)malloc(sizeof(struct node));
                        temp->data=data;
			(temp)->left=NULL;
                        (temp)->right=NULL;
			(*root1)->right = temp;
			rv =1;
                }
		else if((*root1)->left->left == NULL || (*root1)->left->right == NULL)
		{
				temp = (struct node *)malloc(sizeof(struct node));
                        temp->data=data;
                        (temp)->left=NULL;
                        (temp)->right=NULL;

				if((*root1)->left->left == NULL )
					(*root1)->left->left =temp;
				else
					(*root1)->left->right =temp;
				rv = insert(&((*root1)->left),data);
				if(rv == 0)
				{
				printf("\n\r###$$$\n\r");
				insert(&((*root1)->right),data);
				}
		}
	return rv;
}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
//	else
	//	printf("NULL");
}

void main()
{
	struct node *temp=NULL,*root=NULL,*temproot=NULL;
	int i=0;

	

	for(i=1;i<=10;i++)
	{
		insert(&root,i);
	}

	inorder(root);
	
}
