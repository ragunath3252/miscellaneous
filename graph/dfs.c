#include <stdio.h>
#include <queue.h>
#include <string.h>
#include <malloc.h>
#include <graph.h>
#include <list.h>
#include <stack.h>

void dfs(struct graph *g,int start)
{
	struct snode *top=NULL;
	int *visited,i,j;
	struct lnode *p;
//	printf("dfs start");
	visited=(int *)malloc(sizeof(int)*(g->v));
        memset(visited,0,sizeof(int)*(g->v));
//	printf("dfs start");
	push(&top,start);
	
	while(top)
	{
		i=pop(&top);
		printf("#%d\n",i);
		visited[i]=1;
		p = g->array[i];

		while(p)
		{
			if(visited[p->data]==0)
			{
				push(&top,p->data);
				visited[p->data]=1;
		//'		printf("pushed %d\n",p->data);
			}

			p=p->next;
		}
		
	}
			
}

