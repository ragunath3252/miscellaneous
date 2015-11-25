#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void findmin(unsigned long long *a,unsigned long long *min,int n)
    {
        unsigned long long temp=abs(a[0]),res=a[0];
        int i;
        
        for(i=1;i<n;i++)
        {
               if((abs(a[i])) < temp)
                   {
                   temp=abs(a[i]);
			res = a[i];
                  
               }
        }
    
        *min = res;
        
}
void swap(unsigned long long *a,unsigned long long *b)
{
	unsigned long long c;
	
	c = (*a);
	*a = (*b);
	*b = (c);
}
void sort(unsigned long long *a,int n)
{
	int i,j;

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i] > a[j])
			{
				swap(&a[i],&a[j]);
			}
		}
	}
}
int main() {

      int n,i,minindex,resind,m;
      unsigned long long a[100],b[100],c[100]; 
        unsigned long long p,q,j,min,resmin,k,l,res,kk=0,cnt=0;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
    
    scanf("%lld %lld",&p,&q);

	sort(a,n);    
    for(i=0;i<n;i++)
        b[i] = a[i]-p;
    
    findmin(b,&min,n);
    resmin=min;
    l=min;
    res=p;
  
	m=1;
	sort(c,n);
	//sort(a,n);
	for(i=1;i<n;i++)
	{
		c[i]=a[i]-a[i-1];
	//	printf("$ %d %lld\n",i,c[i]);
	}
	// sort(c,n);
	for(i=0;i<n;i++)
        {
         //     c[i]=c[i]-c[i-1];
//                printf("** %d %lld %lld min %lld\n",i,c[i],b[i],min);
                printf("**** %d %lld %lld %lld\n",i,a[i],c[i],b[i]);
        }
    for(j=p+1;j<=q;j++)
    {

	if(c[m]>1)
	{
		c[m]--;
		min = min-1;	
		cnt++;
	}		
	else
	{
		for(i=0;i<n;i++)
		{
			b[i]=a[i]-j;
		//	printf("* %d %lld\n",i,b[i]);
		}
		findmin(b,&min,n);
		m++;
		c[m]--;
		printf("## j %lld %d %lld min %lld %lld cnt %lld\n",j,m,c[m],min,resmin,cnt);
		cnt=0;
	}

        if(resmin < abs(min))
        {
		if(kk==0)
{
		 printf("\nj %lld min %lld res %lld %lldd\n",j,min,resmin,res);
		kk=1;
}
            res = j;
            resmin = abs(min);
		
        }
//	if(j%10000 == 0)
//	printf("\nj %d min %d res %d %d\n",j,min,resmin,res);
    }
  
	printf("%lld",res);       
     
    return 0;
}

