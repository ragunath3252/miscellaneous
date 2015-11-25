#include <stdio.h>

typedef int arr[5];

void func(int (*a)[5])
{
	int i;

	for(i=0;i<5;i++)
		printf("%d\n",*(*a+i));
}
void func1(int (*a))
{
        int i;

        for(i=0;i<5;i++)
                printf("%d\n",*(a+i));
}

void func2(arr *c)
{
	//same as func
}

void main()
{
	arr c;

	c[0]=1;
	c[1]=1;
	c[2]=1;
	c[3]=1;
	c[4]=1;

	func(&c);
	func1(c);
	func2(&c);
	
}
