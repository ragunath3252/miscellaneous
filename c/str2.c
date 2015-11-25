#include <stdio.h>
#include <string.h>

#define str str1[]

void func(char *a,char *b)
{
	*(a+1)='j';
	*(b+1)='j';
	printf("\n%s %s\n",a,b);
}

void main()
{
	char a[]="hi\0frfrf\0dd";/*NULL assigned*/
	char *b="bye;"; /*NULL assigned*/
	char str="hi"; /*NULL not assigned*/
	char d[4]="bye";
	char e[3]="de";

	printf("%s %s %s %ld\n",a,b,str1,strlen(a));

	printf("\n" "hi" "\n" "elele");
	
	printf("\n %ld %ld %ld %ld",strlen(a),sizeof(a),sizeof(b),sizeof(1.1));

	*(a+1)='k';
	printf("%s %s %s %s\n",a,b,str1,strrev(a));

	func(a,b);

	e=d[4];

}
