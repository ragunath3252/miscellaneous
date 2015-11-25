#include <stdio.h>
#include <queue.h>

void main()
{
	struct queue *q;
	struct qnode *p;

	q=create();

	enqueue(q,1);
	enqueue(q,2);
	enqueue(q,3);
	enqueue(q,4);
	enqueue(q,5);
	enqueue(q,6);

	p=dequeue(q);
	while(p)
	{
		printf("%d ",p->data);
		p=dequeue(q);
	}

	enqueue(q,7);
	p=dequeue(q);
	printf("%d ",p->data);

	

}
