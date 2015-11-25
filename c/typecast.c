#include <stdio.h>

int main(void) {
	
    char *c,a=65;	
	void *k;
    c = &a;
    int *i = (int*)(c);
	k=i;
    printf("%p %p %p %p %p\n", i,c,(c+1),(c+2),(c+3));
	 printf("%x %x %x %x %x\n", *i,*c,*(c+1),*(c+2),*(c+3));
    printf("%c %d %d %d %d\n", *i,*c,*(c+1),*(c+2),*(c+3));
    return 1;
}
