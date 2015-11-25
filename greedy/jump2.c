#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define bool int

bool canJump(int* nums, int n) {
    int i,k,j,max;
    int *a;

    if(n==0)
        return false;

    if(n==1)
        return true;


    max=nums[0];
    j=0;

    printf("%d %d\n",j,max);
    while(j < max)
    {
        printf("%d %d %d\n",j,max,n-1);
        if(max>=n-1)
            return true;
        else
        {
            j++;
            if(nums[j]+j > max)
                max = nums[j]+j;
        }
    }
	return false;
}

void main()
{
	int a[5]={4,2,1,1,4};
	if(canJump(a,5)==1)
		printf("\ntrue\n");
	else
		printf("\nfalse\n");
}
