#include <stdio.h>

void spiralPrint(int m, int n, int a[][6])
{
	int p,q,i=0,j=0;
	p=m;
	q=n;

	while(i <= (p/2) && j <= (q/2) )
	{
		while(j<n)
		{
			printf("%d ",a[i][j++]);
		}	
		j--;
		printf("j %d i %d\n",j,i);
		while(i<m-1)
			printf("%d ",a[++i][j]);
		printf("j %d i %d\n",j,i);
		while(j > (q-n))
			printf("%d ",a[i][--j]);
		printf("j %d i %d\n",j,i);
		while(i > (p-m+1))
                        printf("%d ",a[--i][j]);
		printf("j %d i %d\n",j,i);
		n--;
		m--;
	}

	
}

int main()
{
    int a[3][6] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    spiralPrint(3, 6, a);
    return 0;
}
