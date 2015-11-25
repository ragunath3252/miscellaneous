#include <stdio.h>

void main()
{
	unsigned char a = 0x44;
    unsigned char b = 0x88;

    unsigned short val = (((~a) << 8) | (~b));

	printf("%x\n",val);

}
