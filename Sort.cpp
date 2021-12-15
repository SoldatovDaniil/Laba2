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

void bubbleSort(TElem* arr, int N)
{	
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
}

void selectSort(TElem* arr, int N)
{
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
}

void mergeSort(TElem* arr, int start, int finish)
{
	if (start == finish)
	{
		return;
	} 

	int mid = (start + finish) / 2;

	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, finish);

	int a1 = start;  
	int a2 = mid + 1; 
	int* tmp = (int*)malloc(finish * sizeof(TElem)); 

	for (int step = 0; step < finish - start + 1; step++) 
	{
		if ((a2 > finish) || ((a1 <= mid) && (arr[a1] < arr[a2])))
		{
			tmp[step] = arr[a1];
			a1++;
		}
		else
		{
			tmp[step] = arr[a2];
			a2++;
		}
	}
	for (int step = 0; step < finish - start + 1; step++)
		arr[start + step] = tmp[step];
}