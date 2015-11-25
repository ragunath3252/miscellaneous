#include "stdio.h"
#undef AA
#undef ADDMIDIID
#define PP(a,b,c) c s=b; b=a,a=s;

#define QQ(i,j) i##j
void main()
{
	int p,q,r,pq=1234;
	int *p1,*q1;
	int a=0;
	p1=&p;
	q1=&q;
//	(int t);
	int t; p=1,q=2,r=4;
	printf("%s",__PRETTY_FUNCTION__ );
	PP(p1,q1,int *)
	printf("%d %d %d",*p1,*q1,r);
	printf("\n%d\n",QQ(p,q));
}
