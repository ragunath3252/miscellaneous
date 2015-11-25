#include <stdio.h>
#include <malloc.h>

int max(int a,int b)

{

    if(a>b)

        return a;

    else

        return b;

}



int maxSubArray(int* nums, int numsSize) {

    

    int maxi;

    int *arr;

    int i,j;

    

    arr=(int *)malloc(sizeof(int)*numsSize);

    

    arr[0]=nums[0];

    maxi=arr[0];

    for(j=1;j<numsSize;j++)

    {

        arr[j]= max(arr[j-1]+nums[j],nums[j]);

	printf("\n%d %d %d\n",j,arr[j],maxi);
        if(arr[j] > maxi)

            maxi=arr[j];

    }

    

    return maxi;

}

void main()
{
	int a[3]={2,0,2};

	printf("res %d\n",maxSubArray(a,3));
}
