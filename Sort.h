#pragma once

typedef int TElem;

void bubbleSort(TElem* arr, int N, double* pstrt, double* pend);
void selectSort(TElem* arr, int N, double* pstrt, double* pend);
TElem* mergeSort(TElem* arr, TElem* tmp, int start, int finish);