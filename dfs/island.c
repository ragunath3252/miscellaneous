#include <stdio.h>

#define ROW 4
#define COL 4

int numIslands(char grid[][COL], int r, int c,char b[][COL]) {
    int i,j,cnt=0;

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(grid[i][j]== '1')
            {
                if(j >=1 && i >= 1)
                {
		    if(j == c-1)
		    {
			if(grid[i][j-1]=='0' && grid[i-1][j]=='0')
                        cnt++;
		    }
		    else
		    {
                    	if(grid[i][j-1]=='0' && grid[i-1][j]=='0' && b[i][j+1]=='0')
                        cnt++;
		    }
			
                }
                else if(j==0 && i>=1 && grid[i-1][j]=='0' && b[i][j+1]=='0')
                    cnt++;
                else if (i==0 && j>=1 && grid[i][j-1]=='0' )
                    cnt++;
                else if (j==0 && i==0)
                    cnt++;
                else
                    continue;
	//	if(cnt ==2)
		//	printf("%d %d\n",i,j);

            }
        }
    }
    return cnt;
}

void fill(char a[][COL],char b[][COL],int r,int c)
{
	int i,j;

	for(j=0;j<c;j++)
		b[0][j]='0';
	for(i=1;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(a[i][j]=='1' && a[i-1][j]=='1')
				b[i][j]='1';
			else
				b[i][j]='0';	
		}
	}	
}

void print()
{
	
}
void main()
{
	char a[ROW][COL]={"0111","0010","0100","1111"};
	char b[ROW][COL];

	fill(a,b,ROW,COL);
	printf("%d ",numIslands(a,ROW,COL,b));
}
