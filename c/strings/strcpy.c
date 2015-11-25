#include <stdio.h>
#include <string.h>

int main ()
{
   char src[10], dest[50];

   strcpy(src,  "aaadfffffffffaaaaaaaaaerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrwfeeeeeeeeeeeeeeeeeeeeeeeeee");
   strcpy(dest, "This is destination");

//   strncat(dest, src, 100);

   printf("Final destination string : |%s|\n", src);
   
   return(0);
}
