#include <stdio.h>

int main()
{
    int i = 1024;
    for (; i; i >>= 1)
        printf("GeeksQuiz\n",i++);
    return 0;
}
