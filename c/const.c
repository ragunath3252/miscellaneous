#include <stdio.h>

void main()
{
	 const int  i=10;
	int j=20,k=30;
	const int *p;
	int const *q;

	p = &j;	
	*p=9;
	q=&k;
	*q=10;
	k=40;
	

	i=20;	
}
