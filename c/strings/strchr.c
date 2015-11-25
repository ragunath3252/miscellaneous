#include <stdio.h>
#include <string.h>

int main ()
{
   const char str[] = "http://www.\0tutori\0alspoint.com";
   const char ch = '\0';
	char ss[]="point";
	int c=0x1163;
   char *ret;

   ret = strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}
