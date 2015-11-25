#include <stdio.h>

int a[100];
int head=0;
int getip(void)
{
	int i=-1;
	scanf("%d",&i);
	return i;
}

void print_heap(void)
{
	int i;

	printf("\n Heap is");
	for(i=1;i<=head;i++)
	{
		printf("\n\r%d ",a[i]);
	}
}

void swap(int *a,int *b)
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void adjustup(int size)
{
	int par = size/2;
	if(par < 1)
		return;

	if(a[par] > a[size])
	{
		swap(&a[par] ,&a[size]);	
		adjustup(par);
	}
}

void adjustdown(int size)
{
	int small,left,right;	

	left = size*2;
	right = size*2+1;

	if(left > head)
		return;

	if(a[left] < a[right])
		small = left;	
	else
		small = right;

	if(a[size] > a[small])
		swap(&a[size],&a[small]);	

	adjustdown(small);
}

void insert(int ip)
{
	head++;

	a[head] = ip;

	adjustup(head);
}
void build_heap(void)
{
	int i,ip;

	ip = getip();
	while(ip != -1){
		insert(ip);	
		ip = getip();
	}
}
void main()
{
	print_heap();
	build_heap();
	print_heap();

}
