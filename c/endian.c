#include <stdio.h>

typedef struct tagT{

    int a:4;
    int b:4;
    int c:8;
    int d:16;
}T;


int main()
{
    char data[]={0x12,0x34,0x56,0x78};
    T *t = (T*)data;
    printf("a =0x%x\n" ,t->a);
    printf("b =0x%x\n" ,t->b);
    printf("c =0x%x\n" ,t->c);
    printf("d =0x%x\n" ,t->d);

    return 0;
}

