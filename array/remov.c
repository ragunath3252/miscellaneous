#include <stdio.h>

void swap(int *a,int *b)

{

    int temp;

    

    temp = (*a);

    *a = (*b);

    *b=temp;

}



int removeElement(int* nums, int numsSize, int val) {

    int i=0,j=numsSize-1;

    if(numsSize==0)
        return 0;
    while(i<=j)
    {

	while(nums[j]==val && j >=0)
		j--;

	if(j < 0)
		return 0;
        if(nums[i] == val && i <=j)
        {
            swap(&nums[i],&nums[j]);
            j--;
        }

        i++;
    }
	return j+1;
}

void rotate(int* nums, int numsSize, int k) {
    int *a,i;
    int n = numsSize;
    k=k%n;
    a=(int *)malloc(sizeof(int) * k);

    for(i=k;i>0;i--)
	{
        a[k-i]=nums[n-i];
	printf("%d %d %d %d\n",i,k,a[k-i],nums[n-i]);
	}

    for(i=n-1;i>=k;i--)
        nums[i]=nums[i-k];

    for(i=0;i<k;i++)
        nums[i]=a[i];

	printf("%d %d\n",a[0],nums[0]);

	for(i=0;i<n;i++)
		printf("%d ",nums[i] );
}
void main()
{
	int a[3]={1,2,3};

//	printf("%d",rotate(a,2,1));
	rotate(a,3,2);


}
