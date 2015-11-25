#include <stdio.h>
#define ISEQUAL(X, Y) X == Y
#define a 10
#define a 20
int main()
{
    #if ISEQUAL(X, 0)
        printf("Geeks");
    #else
        printf("Quiz");
    #endif
    return 0;
}
