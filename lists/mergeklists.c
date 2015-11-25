#include <stdio.h>
#include <malloc.h>

struct ListNode {

      int val;

      struct ListNode *next;

 };

struct ListNode* findnext(struct ListNode** lists, int listsSize) {

     

     int i=0,small=0,j=0;

     struct ListNode *temp;

     

     while(!lists[i] && i < listsSize)

     {

        i++;

     }

//    	printf("i %d\n",i); 

     if(i==listsSize)

        return NULL;

     

     small = lists[i]->val;
	j=i;
    
	printf("\n small %d i %d\n",small,i); 

     while(i < listsSize)

     {

	if(!lists[i])
	{
		i++;
		continue;
	}

	printf("\nsmall %d i %d vall %d\n",small,i,lists[i]->val);
         if(small > lists[i]->val)

            j=i;

        i++;

     }

     

//	printf("\n small %d i %d\n",small,i);
        

        

     temp = lists[j];

     lists[j] = lists[j]->next;

	printlist(lists[j]);
     return temp;

 }

 

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    

    struct ListNode *result,*head;;

    int i;

    

    if(lists==NULL || listsSize==0)

        return NULL;

//	printlist(lists[0]);
//	printlist(lists[1]);
        

        

    result=findnext(lists,listsSize);
	head = result;


	printlist(result);    

    while(result)

    {

        result->next = findnext(lists,listsSize);

        result = result->next;

    }

    

	printlist(head);
    return head;

    

    

}


void fill(struct ListNode **list)
{

	*list = (struct ListNode *)malloc(sizeof(struct ListNode ));
	(*list)->val = (-1);
	(*list)->next=(struct ListNode *)malloc(sizeof(struct ListNode ));
	(*list)->next->val =6;
	(*list)->next=NULL;
	printlist(*list);
}

void printlist(struct ListNode *list)
{
	printf("\nprinting lists");
	while(list)
	{
		printf("%d",list->val);
		list=list->next;
	}
	printf("\n");
}
void main()
{
	struct ListNode *lists[3];
	struct ListNode **p;
	struct ListNode *temp;

	//p=&lists;
	lists[0]=(struct ListNode *)malloc(sizeof(struct ListNode ));
	lists[0]->val = 2;
	lists[0]->next=NULL;

	fill(&lists[2]);
	lists[1]=NULL;

	printlist(lists[0]);
	printlist(lists[1]);
	printlist(lists[2]);

	temp = mergeKLists(lists,3);

	printlist(temp);	


}
