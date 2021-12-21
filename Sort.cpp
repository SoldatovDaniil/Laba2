#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

typedef int TElem;

bool comp(TElem a, TElem b)
{
	return a > b;
}

void swap(TElem* a, TElem* b)
{
	TElem tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(TElem* arr, int N, double* pstrt, double* pend)
{	
	*pstrt = clock();
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - 1 ; j++)
		{
			if (comp(arr[j], arr[j + 1]))
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	*pend = clock();
}

void selectSort(TElem* arr, int N, double* pstrt, double* pend)
{	
	*pstrt = clock();
	int i, j;
	int pmin = 0; 
	for (i = 0; i < N; i++)
	{	
		pmin = i;
		for (j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[pmin])
			{
				pmin = j;
			}
		}
		swap(&arr[pmin], &arr[i]);
	}
	*pend = clock();

}

TElem* mergeSort(TElem* arr, TElem* tmp, int start, int finish)
{
	if (start == finish)
	{
		tmp[finish] = arr[finish];
		return tmp;
	}
	int mid = start + (finish - start) / 2;
	TElem* arr1 = mergeSort(arr, tmp, start, mid);
	TElem* arr2 = mergeSort(arr, tmp, mid + 1, finish);
	TElem* res = arr1 == arr ? tmp : arr;
	int start1 = start;
	int start2 = mid + 1;
	for (int i = start1; i <= finish; i++)
	{
		if (start1 <= mid && start2 <= finish)
		{
			if (arr1[start1] < arr2[start2])
			{
				res[i] = arr1[start1];
				start1++;
			}
			else
			{
				res[i] = arr2[start2];
				start2++;
			}
		}
		else if (start1 <= mid)
		{
			res[i] = arr1[start1];
			start1++;
		}
		else
		{
			res[i] = arr2[start2];
			start2++;
		}
	}
	return res;
}



