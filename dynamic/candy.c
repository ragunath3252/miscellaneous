#include <stdio.h>
#include <malloc.h>


void main()
{
	unsigned long t,n,i;
	unsigned long *a,*arr,*c;

	scanf("%ld",&n);
	a=(unsigned long *)malloc(sizeof(unsigned long )*n);
	arr=(unsigned long *)malloc(sizeof(unsigned long )*n);
	c=(unsigned long *)malloc(sizeof(unsigned long )*n);	

	t=0;

	while(t<n)
	{
		scanf("%ld",&a[t]);
		t++;
	}

	if(n==1)
	{
		printf("1");
		return ;
	}

	if(a[0]>a[1])
	{
		c[0]=2;
		c[1]=1;
		arr[0]=1;
        arr[1]=3;
	}
	else if(a[0] < a[1])
	{
		c[0]=1;
		c[1]=2;
		arr[0]=1;
        arr[1]=3;
	}
	else
	{
		c[0]=1;
		c[1]=1;
		arr[0]=1;
        arr[1]=2;
	}

	for(t=2;t<n;t++)
	{
		if(a[t] <= a[t-1])
		{
			i=t;
			printf("\n#%d %d %d %d\n",a[t],a[t-1],arr[t-1],t-1);
			while(i >=1 && a[i] < a[i-1])
			{
				//c[t-1]++;
				arr[t-1]++;
				i--;
			
			}
			printf("\n@%d %d %d %d\n",a[t],a[t-1],arr[t-1],t-1);	
			c[t]=1;
			arr[t]=arr[t-1]+c[t];
		}
		else
		{
	//		printf("\n@%d %d %d %d\n",a[t],a[t-1],arr[t],c[t]);
			c[t]=c[t-1]+1;
			arr[t]=arr[t-1]+c[t];
		}

	//	printf("\n%d %d %d %d\n",a[t],a[t-1],arr[t],c[t]);
		
	}	
	printf("\ngggg\n");
	for(t=0;t<n;t++)
	{
		printf("%d %d %d\n",a[t],c[t],arr[t]);
	}
	printf("%ld",arr[t-1]);	

}
