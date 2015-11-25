#include <stdio.h>


int solution(int *A, int N) 
{ 
	int result = 0; 
	int i, j; 
	int map[N];

	for(i=0;i<N;i++)
		map[i]=0;

	for (i = 0; i < N; i++) 
	{
		if(map[A[i]])
		{
			if(abs(map[A[i]]-i)>result)
			result = abs(map[A[i]]-i); 
		}
		if (map[A[i]]==0)
                {
                        map[A[i]]=i;
                }
	}
return result; 
}

void main()
{
	int a[6]={1,2,1,4,2,5};

	printf("%d\n",solution(a,6));
} 
