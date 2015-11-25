#include <stdio.h>

void fn(int **p,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d",p[i][j]);
	}
}

void fill(int **p,int r,int c)
{
        int i,j;
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
			p[i][j]=i+j;
        }
}

int minPathSum(int** grid, int row, int col) {

 		   int dp[row][col];
			int i,j;

		for(i=0;i<row,i++)
		{
			for(j=0;j<col;j++)
			{	
				if((i==0 && j == 0)
					dp[i][j]= grid[0][0];
				else if (i==0)
					dp[i][j]=grid[i][j-1]+grid[i][j];
				else if(j==0)
					dp[i][j]=grid[i-1][j]+grid[i][j];
				else
					dp[i][j]=min(grid[i][j-1],grid[i-1][j])+grid[i][j];
				
			}
		}
		
	return dp[i-1][j-1];
    

    

}

void main()
{
	int r=2,c=2,i;
	
	int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));
//nt a[2][2]={{1,2},{3,4}};
	fill(arr,2,2);
	fn(arr,2,2);

	
}
