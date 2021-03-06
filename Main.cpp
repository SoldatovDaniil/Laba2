#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

#define N 1000
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
	TElem* arr = (TElem*)malloc(N * sizeof(TElem));

	printf("Select the sort type from the list: 1)bubble-sort 2)selection-sort 3)merge-sort\n");
	scanf_s("%d", &ch);

	printf("Not sorted array:\n");
	init(arr);

	for (int i = 0; i < N; i++)
	{
		printf("%4" TE, arr[i]);
	}

	double strt, end;
	double* pstrt = &strt;
	double* pend = &end;

	switch (ch)
	{
	case 1:
		bubbleSort(arr, N, pstrt, pend);
		printf("\nRunning time %lf sec\n", (end - strt) / (CLOCKS_PER_SEC));
		break;
	case 2:
		selectSort(arr, N, pstrt, pend);
		printf("\nRunning time %lf sec\n", (end - strt) / (CLOCKS_PER_SEC));
		break;
	case 3:
		TElem *tmp = (TElem*)malloc(N * sizeof(TElem));
		strt = clock();
		TElem* res = mergeSort(arr, tmp, 0, N - 1);
		end = clock();
		for (int k = 0; k < N; k++)
		{
			arr[k] = res[k];
		}
		printf("\nRunning time %lf sec\n", (end - strt) / (CLOCKS_PER_SEC));
		free(tmp);
	}
	
	printf("\nSorted array:\n"); 
	for (int j = 0; j < N; j++)
	{
		printf("%4" TE, arr[j]);
	}

	bool flag = 0;
	for (int l = 0; l < N - 1; l++)
	{
		if (arr[l] > arr[l + 1])
		{
			flag = 1;
		}
		if (flag)
		{
			break;
		}
	}
	printf("\n-------------------------------------------\n");
	if (flag)
	{
		printf("Result is incorrect");
	}
	else
	{
		printf("Result is correct");
	}

	free(arr);

	return 0;
}