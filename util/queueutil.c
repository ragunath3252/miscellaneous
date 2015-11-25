#include <malloc.h>
#include <queue.h>

//1. Enqueue
//2. Dequeue
//3. create


void enqueue(struct queue *q,int data)
{
	if(q->rear == NULL)
	{
		q->front = (struct qnode *)malloc(sizeof(struct qnode));
		q->front->data = data;
		q->front->next = NULL;
		q->rear = q->front;
		
	}
	else
	{
		q->rear->next = (struct qnode *)malloc(sizeof(struct qnode));
		q->rear->next->data = data;
                q->rear->next->next = NULL;
                q->rear = q->rear->next;
	}
	
}


struct qnode * dequeue(struct queue *q)
{
	struct qnode *temp;
	if(q->front == NULL)
		return;

	temp = q->front;
	q->front=q->front->next;

	if(q->front == NULL)
		q->rear=NULL;

	return temp;
	
}

struct queue* create_queue()
{
	struct queue *temp;

	temp = (struct queue *)malloc(sizeof(struct queue ));

	temp->front = temp->rear = NULL;

	return temp;
}

