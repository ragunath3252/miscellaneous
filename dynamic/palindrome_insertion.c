#include <stdio.h>
#include <string.h>
#include <malloc.h>

int min(int a,int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int pal(char s[])
{
	char *p,*q;
	int i,len;

	len=strlen(s);

	if(len==0 || len==1)
		return 0;

	if(len==2)
	{
		if(s[0]==s[1])
			return 0;
	}

	if(s[0] == s[len-1])
	{
		p=s+1;
		p[len-2]='\0';	
		printf("#### %s\n",p);
		return pal(p);
	}
	else
	{
		p=malloc(100);
		q=malloc(100);

		strncpy(p+1,s,strlen(s));
		p[0]=s[len-1];
		
		strncpy(q,s,strlen(s));
                q[len]=s[0];
		q[len+1]='\0';
		printf("%s %s\n",p,q);
		return 1+min(pal(p),pal(q));
	}
}

void main()
{
	char s[100];

	scanf("%s",s);

	printf("%d \n",pal(s));
}
