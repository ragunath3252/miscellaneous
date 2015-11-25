#include <stdio.h>

void main()
{
	unsigned char a=0x21;

//	a = (a&0xf<<4)|(a>>4);
	a = ((a&0x7)<<5)|(a>>3);

	printf("%x \n",a);
}
