#include <string.h>
#include <stdio.h>

int main()
{
   char str[80] = "This is - www.tutorialspoint.com - website";
    char s[4] = "-";
   char *token;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
      printf( " %s \n", token );
    	s[0]='.';
      token = strtok(NULL, s);
	s[0]='w';
   }
   
   return(0);
}
