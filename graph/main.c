#include <stdio.h>
#include <graph.h>
#include <list.h>
#include <malloc.h>

struct graph * create_graph(int v)
{
	int i;
	struct graph *g;

	g=(struct graph *)(malloc(sizeof(struct graph )));
	g->v = v;
	g->array=(struct lnode **)(malloc(sizeof(struct lnode *)));
	for(i=0;i<v;i++)
		g->array[i]=(struct lnode *)(malloc(sizeof(struct lnode )));

	return g;	
}

void deletelast(struct lnode **head1)
{
	struct lnode *head;

	head=*head1;
	if((*head1)->next == NULL)
		*head1=NULL;
        while(head)
        {	
	//	printf("%p %p\n",&(head),head);
                if(head->next && head->next->next == NULL)
                        head->next=NULL;
		else
                	head=head->next;
        }
}


void addedge(struct graph *g,int src,int dest)
{
	
	insert(&(g->array[src]),dest);
	//printlist(g->array[src]);
}

void main()
{
	int i;
	struct graph *g;
	g = create_graph(5);

	addedge(g, 0, 1);
    addedge(g, 0, 4);
    addedge(g, 1, 2);
    addedge(g, 1, 3);
    addedge(g, 1, 4);
    addedge(g, 2, 3);
	addedge(g, 2, 4);
    addedge(g, 3, 1);


for(i=0;i<5;i++)
{
//	printf("#%p %p\n",&(g->array[i]),g->array[i]);
	deletelast(&(g->array[i]));
	printlist(g->array[i]);
}

	bfs(g,2);
	dfs(g,2);
}
