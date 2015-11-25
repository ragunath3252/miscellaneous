#include <stdio.h>
#include <queue.h>
#include <string.h>
#include <malloc.h>
#include <graph.h>
#include <list.h> 

void bfs(struct graph *g,int start)
{
	int *visited,i,j;
	struct queue *q;
	struct qnode *temp;
	struct lnode *p;

	visited=(int *)malloc(sizeof(int)*(g->v));
	memset(visited,0,sizeof(int)*(g->v));
	q=create_queue();

	enqueue(q,start);
	temp = dequeue(q);
	j=temp->data;
	p=g->array[j];
	while(temp)
	{
		printf("#%d ",j);
//		printlist(p);
		visited[j]=1;
		while(p)
		{
//			printf("@%d %d\n",j,p->data);
			if(visited[p->data]==0)
			enqueue(q,p->data);
			p=p->next;
		}
		temp = dequeue(q);
		if(temp)
		j=temp->data;
	        p=g->array[j];
//		if(p)
//		printf("!%d %d\n",j,p->data);
//		else
//		printf("e!%d\n",j);
	}	
}
