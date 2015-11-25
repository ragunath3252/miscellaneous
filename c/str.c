#include <stdio.h>

void main()
{
	char a[3]="hi";/*NULL assigned*/
	char *b="bye;"; /*NULL assigned*/
	char c[2]="hi"; /*NULL not assigned*/

	printf("%s %s %s\n",a,b,c);
	b = "loo";
	c="po";
	printf("%s %s %s\n",a,b,c);

	printf("%s %u",&"hiiii",&"hiiii");
}
