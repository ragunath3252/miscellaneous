#include <stdio.h>
#include <string.h>


int main()
{
   const char haystack[40] = "";
   const char needle[10] = "Point";
   char *ret;
//	ret=malloc(50);
	scanf("%s",ret);
	printf("The substring is: %s\n", ret);
   ret = strstr(haystack, needle);

   printf("The substring is: %s\n", ret);
   
   return(0);
}
