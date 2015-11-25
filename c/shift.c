#include <stdio.h>

void main()
{
	int a=32;
	unsigned char c=0x80;

	scanf("%d",&c);

	printf("%d %x %x %d\n",a,a<<24,a<<-8,c<<1);

	printf("%c",c);
}
