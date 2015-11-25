#include <stdio.h>
#include <malloc.h>

/*
int maxProfit(int* prices, int pricesSize) {

  

            int min,max,i=0,j=0,old=0;

            

            min =prices[0];

            max = prices[0];

            

            while(i < pricesSize)

            {

                j=i;

                while(prices[j] >= max  && j < pricesSize)

                {

                    max=prices[j];

                    j++;

                }

                

                if((max-min) > old)

                old = max-min;

                

                

                

                

                    

                i++;

		if(prices[i]<min)
                min =prices[i];

                max = prices[i];

                

            }

            return old;

}
*/

int max(int a,int b)

{
    if(a>b)
        return a;
    else
        return b;
}
int maxProfit(int* prices, int pricesSize) {
            int min,i;
            int *a;
            min = prices[0];

            a=(int *)malloc(sizeof(int)*pricesSize);
            a[0]=0;
            for(i=1;i<pricesSize;i++)
            {
                if(prices[i] < min)
                    min = prices[i];
		printf("%d %d %d@\n",a[i],prices[i],min);
                a[i]=max(prices[i]-min,a[i-1]);
		printf("%d %d %d#\n",a[i],prices[i],min);
            }
            return a[i-1];
}

void main()
{
	int a[6]={2,4,1,0,0,0};

	printf("\nres %d\n",maxProfit(a,6));
}
