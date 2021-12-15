#pragma once

typedef int TElem;

void bubbleSort(TElem* arr, int N);
void selectSort(TElem* arr, int N);
TElem* mergeSort(TElem* arr, TElem* tmp, int start, int finish);