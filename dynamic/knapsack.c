#include <stdio.h>

int knap(int *wei,int *val, int n, int t)
{
	int res1=0,res2=0;
	if(t<=0)
		return -1;
	if(n==0)
	{
		if(wei[0]<=t)
			return val[0];
		else
			return 0;
	}

	res1= knap(wei,val,n-1,t-wei[n]);
	res2= knap(wei,val,n-1,t);
	printf("%d %d %d\n",res1+val[n],res2,wei[n]);
	if(res1 != -1 && res1+val[n]>res2)
	{
		printf("#%d %d\n",res1+val[n],wei[n]);
		return res1+val[n];
	}
	else
	{
		printf("*%d %d\n",res2,wei[n]);
		return res2;
	}
}

void main()
{
	int n,t,i,j;
	int *wei,*val;

	scanf("%d",&n);
	
	wei = malloc(sizeof(int)*n);
	val = malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	for(i=0;i<n;i++)
        {
                scanf("%d",&wei[i]);
        }
	scanf("%d",&t);

	printf("%d\n",knap(wei,val,n-1,t));
}
