#include <stdio.h>
#include <string.h>


int main()
{
   const char haystack[40] = "";
   const char needle[10] = "Point";
   char *ret;

   ret = strstr(NULL, needle);

   printf("The substring is: %s\n", ret);
   
   return(0);
}
