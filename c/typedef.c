#include <stdio.h>

typedef int * p;
typedef struct b{
	int a;
}*c;
void main()
{
	int i=10;
	struct b ae;
	c aw;
	p q=&i;

	printf("%d ",*q);

	aw = &ae;
	printf("%d %p %p %p",aw->a,aw,*aw,&ae);
}
