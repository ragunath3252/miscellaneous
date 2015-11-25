#include <stdio.h>
#include <malloc.h>

#define false 0
#define true 10

struct TreeNode {

      int val;

      struct TreeNode *left;

      struct TreeNode *right;

  };


int isValidBST(struct TreeNode* root) {

    

    static struct TreeNode *prev=NULL;

    if(root)

    {

        if(isValidBST(root->left) ==false)

            return false;

        if(prev && prev->val >= root->val)

            return false;

        

        prev=root;

        return (isValidBST(root->right));

        

    }

    

    return true;

}

void main()
{
	struct TreeNode *temp;

	temp =(struct TreeNode *)malloc(sizeof(struct TreeNode) );
	temp->val=1;
	temp->left=NULL;
	temp->right=NULL;

	printf("\n%d\n",isValidBST(temp));
}

