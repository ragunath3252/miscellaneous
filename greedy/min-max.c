#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void findmin(unsigned long long *a,unsigned long long *min,int n)
    {
        unsigned long long temp=abs(a[0]);
        int i;
        
        for(i=1;i<n;i++)
        {
               if(abs(a[i]) < temp)
                   {
                   temp=abs(a[i]);
                  
               }
        }
    
        *min = temp;
        
}
int main() {

      int n,i,minindex,resind,res;
      unsigned long long a[100],b[100]; 
        unsigned long long p,q,j,min,resmin;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    
    scanf("%lld %lld",&p,&q);
    
    for(i=0;i<n;i++)
        b[i] = a[i]-p;
    
    findmin(b,&min,n);
    resmin=min;
    res=p;
    
    for(j=p+1;j<=q;j++)
    {
        for(i=0;i<n;i++)
	{
		
            b[i]=b[i]-1;
//		printf("%d ",b[i]);
	}
	
        findmin(b,&min,n);
	printf("\nj %d min %d\n",j,min);
        if(resmin < min)
        {
            res = j;
            resmin = min;
        }
    }
  
	printf("%d",res);       
     
    return 0;
}

