#include <stdio.h>
#include <malloc.h>

struct TreeNode {

      int val;
     struct TreeNode *left;
      struct TreeNode *right;
};

int kthSmallest(struct TreeNode* root, int k) {

    static int cnt=0;
    int a=0;

    if(root)
    {
    a=kthSmallest(root->left,k);

    if(a!=-1)
    {
        return a;
    }
    cnt++;

    if(cnt == k)
            return root->val;
    a=kthSmallest(root->right,k);
    if(a!=-1)
    {
        return a;
    }
    }
    return -1;
}
struct TreeNode* newNode(int data)
{
  struct TreeNode* node = (struct TreeNode*)
                       malloc(sizeof(struct TreeNode));
  node->val = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
  struct TreeNode *root = newNode(1);
//  root->left        = newNode(2);
  root->right       = newNode(2);
 // root->left->left  = newNode(1);
 // root->left->right = newNode(3); 

	printf("\nres ######%d\n",kthSmallest(root,2));

}
