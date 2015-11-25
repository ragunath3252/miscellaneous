#include<stdio.h>
 
/* Searches the element x in mat[][]. If the element is found, 
    then prints its position and returns true, otherwise prints 
    "not found" and returns false */

int recur(int a[][4],int i,int j,int x)
{
	int f=0;
	if(a[i][j] == x)
		return 1;
	else if(a[i][j] < x)
	{
		if(j < 4)
		{
		f=recur(a,i,j+1,x);	
		if(f==1)
			return f;
		}
		if(i<3)
		{
		f=recur(a,i+1,j,x);
		if(f==1)
                        return f;
		}
	}
	else
		f=0;
	return f;
}
int search(int mat[3][4], int x)
{
	if(recur(mat,0,0,x))
		printf("found");
	else
		printf("not found");
}
 
// driver program to test above function
int main()
{
  int mat[3][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                  };
  search(mat, 35);
  search(mat, 20);
search(mat, 31);
  return 0;
}
