#include <stdio.h>


struct TreeNode {

      int val;

      struct TreeNode *left;

      struct TreeNode *right;

  };

 struct node {

   struct TreeNode *data;

   struct node *next;

 };
struct queue{

   struct node *front;

   struct node *rear;

 };

 

 struct queue * queue_init()

 {
	struct queue *q;
     q=malloc(sizeof(struct queue));

     q->front=q->rear=NULL;
	return q;

 }

 void enqueue(struct queue *q,struct node *t)

 {

     if(q->rear==NULL)

     {
         q->front=q->rear=t;

         return;

     }

     

     q->rear->next = t;

     q->rear=t;

 }

 

 struct node * dequeue(struct queue *q)

 {
	struct node *t;
     if(q && q->front==NULL)
     {
        return NULL;
     }

     if(q->front->next==NULL)

     {

         t = q->front;

         q->front=q->rear=NULL;
	return t;

     }

     

     t = q->front;

     q->front=q->front->next;
     return t;

 }

 

 void preorder(struct queue *q,struct TreeNode *root)

 {

     struct node *t;
	
	t=malloc(sizeof(struct node));
     if(root)

     {

         t->data=root;

         t->next=NULL;

         

         enqueue(q,t);

         preorder(q,root->left);

         preorder(q,root->right);

     }   

     

     

 }

void flatten(struct TreeNode* root) {

    struct queue *q;
    struct node *t;
	struct TreeNode *temp;

	temp = root;

    q=queue_init();
    preorder(q,root);

    t=dequeue(q);
  //root->val=t->data;
	root=t->data;
	temp = root;
	printf("%d ",root->val);
    t=dequeue(q);

	while(t!=NULL)
    {
	temp->right=t->data;
	temp->left=NULL;
	temp=temp->right;
	printf("%d ",temp->val);
	
	t=dequeue(q);

    }

    

}
void postorder(struct TreeNode *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->val);
	}
}
struct TreeNode* newNode(int data)
{
    struct TreeNode* node = (struct TreeNode*)
                             malloc(sizeof(struct TreeNode));
    node->val  = data;
    node->left  = NULL;
    node->right = NULL;
 
    return(node);
}
void main()
{
	struct TreeNode *root;

	root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(5);
	root->left->left=newNode(3);
	root->left->right=newNode(4);
	root->right->right=newNode(6);
	
	flatten(root);
	postorder(root);
}
