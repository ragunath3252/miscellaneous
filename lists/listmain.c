#include <stdio.h>
#include <list.h>


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
