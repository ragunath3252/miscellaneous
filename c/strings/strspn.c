#include <stdio.h>
#include <string.h>

int main ()
{
   int len;
   const char str1[] = "ZEFG019AB874";
   const char str2[] = "ABCD";

   len = strspn(str1, str2);


   printf("Length of initial segment matching %d\n", len );

len = strcspn(str1, str2);


   printf("Length of initial segment matching %d\n", len );

   
   return(0);
}
