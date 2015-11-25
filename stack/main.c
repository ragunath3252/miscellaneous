#include <stdio.h>
#include <stack.h>

void main()
{
        struct snode *top;
        int i;
//      top = create_stack();
        top=NULL;
        push(&top,0);
	printf("top %d\n",topofstack(top));
        push(&top,1);
        push(&top,2);
        push(&top,3);

        for(i=0;i<8;i++)
	{
	printf("top %d\n",topofstack(top));
        printf("%d",pop(&top));
	}

}

