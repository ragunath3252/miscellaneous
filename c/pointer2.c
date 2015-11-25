#include <stdio.h>
void func(char *p)
{
	printf("%s",p);
}
void main()
{
	char *ptr[]={"aa","ee","cc","dd"};
	char *p,**q;

	func(*ptr+1);

	q=ptr+1;
	q++;
	p=*(ptr+1);
	printf("%s %s\n",*q,p);
	
}
