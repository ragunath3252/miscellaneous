#include <stdio.h>

void main()
{
	int arr[3]={1,8,13};
	int *p;

	p= arr;
	printf("%d %d\n",*p,*p+1);
	printf("%d\n",*p++);
	printf("%d\n",*p);
}
