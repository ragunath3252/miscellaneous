#include <stdio.h>

void print(int a[])
{
	int i;

	for(i=0;i<4;i++)
		printf("%d ",a[i]);

	printf("\n");
}
void func(int (*arr)[2])
{
	int i,j;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			printf("%d ",arr[i][j]);
}
void main()
{
	int a[4]={1,2,3,4};
	int b[2][2]={{1,2},{3,4}};
	int *p[]={a,a+2,a+1,a+3};
	int **ptr=p;
	int *k;

	printf("\n%d %p %p %p\n",*a,a,a+1,*(&a)+1);

	printf("\n%p %p %p %p %p\n",a,p,ptr,*ptr,*p);
//	printf("\n%p %p %p\n",a+1,p+1,ptr+1);
//	printf("\n%lu %lu %lu\n",sizeof(a),sizeof(p),sizeof(ptr));

//	print(p);
//	(*ptr)++;
//	printf(p);
//	p[0]++;
//	k=*ptr++;
	k= ++ptr;
	printf("\na %p p %p ptr %p *ptr %p *p %p k %p\n",a,p,ptr,*ptr,*p,k);
//	print(*p);
//	print(a);

	func(b);

	
}
