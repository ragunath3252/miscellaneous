#include <stdio.h>
#include <malloc.h>

struct TreeNode {

      int val;
     struct TreeNode *left;
      struct TreeNode *right;
};

struct TreeNode* newNode(int data)
{
  struct TreeNode* node = (struct TreeNode*)
                       malloc(sizeof(struct TreeNode));
  node->val = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

struct TreeNode* invertTree(struct TreeNode* root) {

	struct TreeNode *temp;
    if(root)
    {
	temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
    return NULL;
}

void inorder(struct TreeNode* root)
{
	if(root)
{
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);

}
}
 
/* Driver program to test above functions*/
int main()
{
  struct TreeNode *root = newNode(4),*temp;
  root->left        = newNode(2);
  root->right       = newNode(7);
 root->left->left  = newNode(1);
  root->left->right = newNode(3);
root->right->left  = newNode(6);
  root->right->right = newNode(9); 

inorder(root);

temp = invertTree(root);
printf("\n");
inorder(temp);

}
