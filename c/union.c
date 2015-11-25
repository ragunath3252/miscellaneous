#include <stdio.h>

union a{
	struct data{
	int i;
	}r;

	char d[5];
//	short d[5];
};



void main()
{
	union a u;

	int *p=&(u.r.i);
	u.r.i=0x4142;
	

	printf("%c %c %ld %ld\n",u.d[0],u.d[4],sizeof(int),sizeof(u));	
//	printf("%d %ld %ld\n",u.d,sizeof(int),sizeof(u));
	{
		int i;

		u.d[4]=0x46;
		u.d[7]=0x41;
		for(i=0;i<8;i++)
			printf("%c\n",u.d[i]);

		printf("%x\n",u.r.i);

		printf("%x\n",*p);
		p++;
		printf("%x\n",*(p));
	}

}
