#include <stdio.h>
#include <malloc.h>


int max(int a,int b)

{

    if (a> b)

        return a;

    else

        return b;

}



int rob(int* nums, int numsSize) {

    int *a,i;

    

    a=(int *)malloc(sizeof(int) * numsSize);

    

    if(numsSize == 0)

        return 0;

    

    if(numsSize == 1)

        return nums[0];

        

    if(numsSize==2)

        return max(nums[0],nums[1]);

        

    a[0]=nums[0];

    a[1]=max(nums[0],nums[1]);

   printf("0 %d 1 %d\n",a[0],a[1]); 

    for(i=2;i<numsSize;i++)

    {

        a[i] = max(a[i-1],nums[i]+a[i-2]);
	printf("\n %d %d %d %d %d\n",i,a[i],nums[i],nums[i-1],nums[i-2]);

    }


    return max(a[i-1],a[i-2]);

    

}

void main()
{
	int a[4]={2,1,1,2};
	printf("\nres %d\n",rob(a,4));	
}
