#include <stdio.h>

void main()
{
	int i,j=0,k=0;
	int a[6] = {10, 20, 60, 40, 50, 30};

	for(i=0;i<5;i++)
	{
		printf("\n\r!%d %d",a[i],a[i+1]);
		if(a[i] > a[i+1] )
		{
			printf("\n\r#%d ",i);
			if(j==0)
				j=i;
			else
				k=i+1;
		}
		
	}

	printf("\n\r%d %d\n\r",j,k);
	i=a[j];
	a[j]=a[k];
	a[k]=i;

	for(i=0;i<6;i++)
		printf("%d ",a[i]);
}
