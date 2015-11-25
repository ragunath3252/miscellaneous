#include <stdio.h>
#include <string.h>

int main()
{
   char src[100];
   char dest[5];
  
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.comkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkdddddddddddddddddddddddddddddddk");
   strncpy(dest, src, 10);

   printf("Final copied string : %s\n", dest);
   
   return(0);
}
