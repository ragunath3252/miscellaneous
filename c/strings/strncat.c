#include <stdio.h>
#include <string.h>

int main ()
{
   char src[10], dest[10];

   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");

   strncat(dest, src, 1225);

   printf("Final destination string : |%s|\n", dest);
   
   return(0);
}
