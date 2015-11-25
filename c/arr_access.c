#include <stdio.h>

void func(int a)
{

}

void main()
{
	int a[5]={1,8,11,14,19};
	int b[2][5]={{1,8,11,14,19},{11,22,33,44,55}};
	int *p;

//	p=a;
//	func(a[0]);
	printf(" %p %p %p\n",*a,a,*a);
	printf(" %p %p %p\n",*a+1,a+1,*a+1);

//	p=b;
	printf(" %p %p %p\n",*b,b,*b);
        printf(" %p %p %p\n",*b+1,b+1,*b+1);

	printf(" %p %p %p\n",b[0],b[1],b);
	printf(" %p %p %p\n",b[0]+1,b[1]+1,b);

}
