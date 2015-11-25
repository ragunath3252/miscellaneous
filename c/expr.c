#include <stdio.h>
#include <malloc.h>


void main()
{
	int i=1;
	int p[10][10];

//	p=(int *)malloc(sizeof(int)*2);
	printf("%d %d\n",i,i++);

//	p = &i;

//	printf("%d",*(p));

//	(*p)++ = 20;

//	printf("\n%d ",*(p));
//	printf("\n%d ",*(--p));
	printf("\n%p  ",p);
	printf("\n%p  ",p+1);

	int j=2,k=0,m;
	i=-3;
	m= ++i || ++j && ++k;

	printf("%d %d %d %d\n",i,j,k,m);
}
