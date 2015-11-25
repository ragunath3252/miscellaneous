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
//	printf("%d %d %d\n",res1+val[n],res2,wei[n]);
	if(res1 != -1 && res1+val[n]>res2)
	{
//		printf("#%d %d\n",res1+val[n],wei[n]);
		return res1+val[n];
	}
	else
	{
//		printf("*%d %d\n",res2,wei[n]);
		return res2;
	}
}

int knap_dyn(int *wei,int *val, int n, int t)
{
	int k[n][t+1];
	int i,j,res1,res2;

	for(i=0;i<n;i++)
		k[i][0]=0;

	for(i=1;i<t+1;i++)
	{
		if(wei[0]<=i)
                k[0][i]=val[0];
		else
		k[0][i]=0;
	}

	for(i=1;i<n;i++)
	{
		for(j=1;j<t+1;j++)
		{
			res1=k[i-1][j];
			if(j-wei[i]>=0)
			res2=k[i-1][j-wei[i]];
			else
				res2=-1;
			if(res2!=-1 && res2+val[i]>res1)
				k[i][j]=res2+val[i];
			else
				k[i][j]=res1;
		}
	}

	for(i=0;i<n;i++)
        {
                for(j=0;j<t+1;j++)
                {
			printf("%d ",k[i][j]);
		}
		printf("\n");
	}

	return k[n-1][t];
	
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

	printf("#%d#\n",knap_dyn(wei,val,n,t));
	printf("%d\n",knap(wei,val,n-1,t));
}
