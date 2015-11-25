#include <stdio.h>

#define PRINT(x) 'x/0'
#define INC(x) x++

#define PR(x,...) {printf("%d ",x,##__VA_ARGS__);}
void main()
{
	int x=0,j;
//	printf("%s",PRINT(x));
	PR(9,7,8)

        j=INC(9);
}
