bool canJump(int* nums, int n) {

    

    int i,k,j;

    int *a;

    

    if(n==0)

        return false;

    

    if(n==1)

        return true;

    

    k=1;

    a=(int *)malloc(sizeof(int)*n);

    

    for(i=n-2;i>=0;i--)

    {

        if(nums[i] >= k )

            a[i]=1;

        else

        {

            j=nums[i];

            while(j--)

            {

                if(a[i+j]==1)

                {

                    a[i]=1;

                    break;

                }

            }

        }

        

        k++;

    }

    

    if(a[0]==1)

        return true;

    else

        return false;

    

}
