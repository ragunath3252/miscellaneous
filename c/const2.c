#include <stdio.h>

 void func(int *a)
{
	int jj=90;
	*a=jj;
}
void main()
{
	 const int  i=10,ll;
	int j=20,k=30;
	const int *p;
	int const *q;
	int *const r=&i;
	const int * const s=&k;
	int *t;
	const int arr[5]={1,2,3,4,5};

	ll=0;
	p = &j;	
//	*p=9;
	q=&k;
//	*q=10;
	k=40;
//	r=&i;	
	*r=100;
//	*s=90;
	t=&i;
	*t=1;
	*r=100;
	printf("%d %d",*r,i);

	func(&arr[3]);
	printf("\n%d %d",*r,arr[3]);

//	i=20;	
}
