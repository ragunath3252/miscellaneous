#include <stdio.h>
#include <malloc.h>

struct ListNode {

      int val;

      struct ListNode *next;

 };

 



// Definition for a binary tree node.

  struct TreeNode {

      int val;

      struct TreeNode *left;
      struct TreeNode *right;

 };


struct TreeNode* sortedListToBST(struct ListNode* head) {

    struct TreeNode*  root;

    struct ListNode *slow,*fast,*middle,*prev=NULL,*right;

    

    slow=head;

    fast=head;

    

    if(head==NULL)

        return NULL;

    

    while(slow && fast)

    {

        if(fast->next == NULL)

        {

            middle = slow;

            break;

        }

        

        if(fast->next->next == NULL)

        {

            middle=slow;

            break;

        }

        

        prev = slow;

        slow = slow->next;

        fast = fast->next->next;

        

    }

    

    if(prev)

        prev->next=NULL;

    else

        head=NULL;

        

    right = middle->next;

        

    

    root=(struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = middle->val;
	printf("\n## %d",root->val);

    root->left=sortedListToBST(head);
	if(root->left)
	printf(" ## %d",root->left->val);

    root->right=sortedListToBST(right);
	if(root->right)
	printf("## %d\n",root->right->val);

    return root;

    

}

void inorder(struct TreeNode *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}

void printlist(struct ListNode *list)
{
        printf("\nprinting lists");
        while(list)
        {
                printf("%d",list->val);
                list=list->next;
        }
        printf("\n");
}

void main()
{
	struct ListNode *head=NULL,*temp;
	struct TreeNode *root;
	int i;

	for(i=7;i>=0;i--)
	{
		temp = (struct ListNode *)malloc(sizeof(struct ListNode ));
		temp->val=i;
		temp->next=head;
		head=temp;
		
		
	}

	printlist(head);

	root=sortedListToBST(head);
	inorder(root);
	

}
