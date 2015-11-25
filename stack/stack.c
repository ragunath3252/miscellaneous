#include <stdio.h>
#include <stack.h>
#include <malloc.h>

struct snode *create_stack()
{
	struct snode *top;
	
	top = (struct snode *)malloc(sizeof(struct snode));
	return top;
}

int isempty(struct snode *top)
{
	if(!top)
		return 1;
	else
		return 0;
}

void push(struct snode **top,int data)
{
	struct snode *temp;

	temp = (struct snode *)malloc(sizeof(struct snode ));
	temp->data=data;
	temp->next=*top;
	*top=temp;
	
}

int pop(struct snode **top)
{
	int i;

	if(isempty(*top))
		return -1;
	
	i=(*top)->data;
	
	*top = (*top)->next;

	return i; 
}

int topofstack(struct snode *top)
{
	if(top)
		return top->data;
	else
		return -1;
}

