#include <stdio.h>

void test()
{
	int i,j=0,len=0;
	char s[100];
	char p[100];

	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)
	{
		if(i<len-1 && s[i]=='a' && s[i+1]=='c')
		{
			i++;
			continue;
		}

		if(i<len-2 && s[i]=='a' && s[i+1]=='b' && s[i+2]=='c')
                {
                        i++;
			i++;
                        continue;
                }

		if(s[i]=='b')
		{
			continue;
		}
		

		p[j++]=s[i];
	
	}
	p[j]='\0';

	printf("%s %s\n",s,p);
}

void main()
{
	test();
	
}
