#include <stdio.h>
#include <malloc.h>
#include <string.h>

int check(char a,char b)

{

    if(a == '2')

    {
	
        if(b <='6' && b > '0')

            return 1;
	else if(b=='0')
		return 2;

    }

	if(a == '1')

    {

        if(b <='9' && b > '0')

            return 1;
        else if(b=='0')
                return 2;

    }

    

    return 0;

}



int numDecodings(char* s) {

    

    int *dp;

    int len=strlen(s),i=1;

    

    if(len==0)

        return 0;

    

    dp=(int *)malloc(sizeof(int)*len);

    

if(s[0] == '0')
	return 0;

dp[0]=1;




	printf("\n%d %d",dp[0],i);
    for(i=1;i<len;i++)

    {

	if(s[i]=='0')
	{
		if(! (s[i-1] <='2' && s[i-1] > '0') )
			return 0;
	}

        if(check(s[i-1],s[i])==1)

            dp[i]=dp[i-1]+1;
	else if (check(s[i-1],s[i])==2)
	{
		printf("###");
		if(i-2 >= 0)
		{
			printf("@@@");
			if(s[i-2] <= '2' && s[i-2] > '0')
				dp[i]=dp[i-1]-1;
			else
				dp[i]=dp[i-1];
				
		}
		else
			dp[i]=dp[i-1];
	}
        else

            dp[i]=dp[i-1];

	printf("\n%d %d\n",i,dp[i]);

    }

    

    return dp[i-1];

    

    

}


void main()
{
		printf("\nres %d\n",numDecodings("1212"));
}
