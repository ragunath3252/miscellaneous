#include <stdio.h>
#include <malloc.h>

int minpath(int r,int c, int grid[][c],int n,int int **dp)
{
	if(r <= 0 || c <=0)
		return 0;
//
	if(dp[r-1][c-1] != -1)
		return dp[r-1][c-1];

	

	
}

int minPathSum(int **grid,int r,int c) 
{


	int i,j;

	int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));


	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++);
			arr[i][j]=-1;
	}

	minpath(grid,r,c,c,arr);

//	return arr[r-1][c-1];
}

void main()
{
	int a[2][2],i,j;
	minPathSum((int **)a,2,2);
	for(i=0;i<2;i++)
        {
                for(j=0;j<2;j++)
                        printf("%d",a[i][j]);
        }

}
