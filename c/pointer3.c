#include <stdio.h>

void main()
{
	int a[]={1,2,3};
	int *p;
	int j;

	p=a;
	for(j=0;j<3;j++)
	{
		printf("%d",*p);
		p++;
	}
}
