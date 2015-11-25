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
		printf("%d ",a[i]);
	}
	printf("\n");
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
	if(right > head)
		small = left;
	else
	{
		if(a[left] < a[right])
			small = left;	
		else
			small = right;
	}
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

int deletemin(int size)
{
	int i;

	i = a[1];

	swap(&a[1],&a[head]);
	print_heap();
	head--;

	adjustdown(1);

	return i;
	
}
void main()
{
	int n,i;
	build_heap();
	print_heap();

	n= head;

	for(i=0;i<n;i++)
	{
		printf("#%d ",deletemin(head));
	}

	head=10;
	print_heap();

}
