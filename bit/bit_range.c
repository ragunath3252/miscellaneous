#include <stdio.h>
void main()
{
	char a=0,b=0x95,c;

	int p=5,q=3;
	c=b>>q;
	c=c<<q;
	c=c<<(7-p);
	c=c>>(7-p);
//=((((c)<<q)<<(7-p))>>(7-p));
	printf("%x\n",c);
}
