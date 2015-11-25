#include <stdio.h>
#include <malloc.h>
#include <list.h>

void insert(struct lnode **head,int data)
{
	struct lnode *temp;
	struct lnode *f;

	f=*head;
	temp = (struct lnode *)malloc(sizeof(struct lnode));

	temp->data = data;

	if(*head == NULL)
		*head = temp;
	else
	{
		temp->next=(*head);
		*head = temp;	
	}
	printlist(*head);
	
}

void printlist(struct lnode *head)
{
	while(head)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}
/*
void main()
{
        struct lnode *list;

        insert(&list,1);
        insert(&list,2);
        insert(&list,3);
        insert(&list,4);
        insert(&list,5);
        insert(&list,6);

        printlist(list);
}
*/
