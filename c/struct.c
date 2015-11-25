#include <stdio.h>
#include <string.h>

typedef int * p;
typedef struct b{
	int a;
	char name[10];
}*c;
void main()
{
	int i=10;
	struct b ae;
	c aw;
	p q=&i;

	
	printf("%d ",*q);

	aw = &ae;
	strcpy(aw->name,"hi\0");
	printf("%d %p  %p %s\n",aw->a,aw,&ae,(*aw->name));
}
