#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define bool int
int isvalid(char c)

{

    if(c >= 48 && c <= 57)

        return 0;

    else if(c >= 65 && c <= 90)

        return 0;

    else if (c >= 97 && c <= 122)

        return 0;

    else

        return 1;

}



bool isPalindrome(char* s) {

    char *t;

    

    if(s==NULL)

        return true;

    t=s+strlen(s)-1;

    while(t > s)

    {

        while(t && isvalid(*t))

            t--;

        while(s && isvalid(*s))

            s++;

            

        if((*t != *s) && (abs(*t-*s)!=22))

            return false;

        

        t--;

        s++;

            

    }

    return true;

}

void main()
{
	printf("## %d\n",isPalindrome("A man, a plan, a canal: Panama"));
}
