#include <stdio.h>


int solution(int *A, int N) 
{ 
	int result = 0; 
	int i, j; 

	for (i = 0; i < N; i++) 
	for (j = 0; j < N; j++) 
		if (A[i] == A[j]) 
			if (abs(i - j) > result) 
				result = abs(i - j); 
return result; 
}

void main()
{
	int a[6]={1,2,1,4,2,9};

	printf("%d\n",solution(a,6));
} 
