#include <stdio.h>

void printUnion(int arr1[], int arr2[], int m, int n)
{
	int i=0,j=0;

	while(i < m && j < n)
	{
#if 0
		if(i==m && j < n)
		{
			printf("%d ",arr2[j]);
                        j++;
		}
		else if(i<m && j == n)
                {
                        printf("%d ",arr1[j]);
                        i++;
                }
		else	
		{
#endif
		if(arr1[i] == arr2[j])
		{
			printf("%d ",arr1[i]);
                        i++;
			j++;
		}
		else if(arr1[i] < arr2[j])
		{
//			printf("%d ",arr1[i]);
			i++;
		}
		else
		{
  //                      printf("%d ",arr2[j]);
                        j++;
                }
		}
//	}	
}

int main()
{
  int arr1[] = {1, 2, 4, 5, 6};
  int arr2[] = {2, 3, 5, 7};
  int m = sizeof(arr1)/sizeof(arr1[0]);
  int n = sizeof(arr2)/sizeof(arr2[0]);
  printUnion(arr1, arr2, m, n);
  return 0;
}
