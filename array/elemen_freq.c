#include <stdio.h>

void printfrequency(int arr[],int n)
{
	int i,j;
    // Subtract 1 from every element so that the elements
    // become in range from 0 to n-1
    for (j =0; j<n; j++)
        arr[j] = arr[j]-1;
 
    // Use every element arr[i] as index and add 'n' to
    // element present at arr[i]%n to keep track of count of
    // occurrences of arr[i]
    for (i=0; i<n; i++)
	{
        arr[arr[i]%n] = arr[arr[i]%n] + n;
	printf("\n\r%d %d",i,arr[i]);
	}
 
    // To print counts, simply print the number of times n
    // was added at index corresponding to every element
    for (i =0; i<n; i++)
        printf("\n\r %d   -> %d %d",i+1,arr[i]/n,arr[i]);
}
 
// Driver program to test above function
int main()
{
    int arr[] = {2, 3, 3, 2, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printfrequency(arr,n);
    return 0;
}
