#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

#define N 10
#define TE "d"


typedef int TElem; 

void init(TElem* arr)
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand()% 100;
	}
}


int main()
{
	int ch; 
	TElem arr[N];

	printf("Select the sort type from the list: 1)bubble-sort 2)selection-sort 3)merge-sort\n");
	scanf_s("%d", &ch);

	init(arr);

	printf("Not sorted array:\n");
	for (int i = 0; i < N; i++)
	{
		printf("%4" TE, arr[i]);
	}


	switch (ch)
	{
	case 1:
		bubbleSort(arr, N);
		break;
	case 2:
		selectSort(arr, N);
		break;
	case 3:
		mergeSort(arr, 0, N - 1);
	}

	printf("\nSorted array:\n"); 
	for (int j = 0; j < N; j++)
	{
		printf("%4" TE, arr[j]);
	}
	return 0;
}