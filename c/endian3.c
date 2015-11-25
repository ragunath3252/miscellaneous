#include <stdio.h>

void main()
{
	int i=320;

	char *ptr= (char *)&i;

	printf("%d %d %d %d\n",*ptr,*(ptr+1),*(ptr+2),*(ptr+3));
}
