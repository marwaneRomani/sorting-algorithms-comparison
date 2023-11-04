#include "../utils/utils.h"
#include <stdlib.h>

void bubbleSort(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (*(arr+j) > *(arr+j+1)) {
                // Swap arr[j] and arr[j+1]
                swap((arr+j), (arr+j+1));
            }
        }
    }
}


void selectionSort(int *array,int size) {
	int i, j, min_idx;

	if (!array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;

		if (i != min_idx)
		{
			swap(&array[min_idx], &array[i]);
		}
	}
}

void quickSort(int *array, int size)
{
	int pivot;

	if (!array || size < 2)
		return;

	/* partition and get pivot index */
	pivot = partition(array, size);

	/* repeat for left of index */
	quickSort(array, pivot);
	/* repeat for index and right */
	quickSort(array + pivot, size - pivot);
}

void heapSort(int *array, int size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = size / 2; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[i], &array[0]);
		
		heapify(array, i, 0, size);
	}
}

void insertionSort(int *array, int size) {
  for (int i = 1; i < size; i++) {
    int tmp = array[i];
    int j = i - 1;

    while (tmp < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = tmp;
  }
}

void mergeSort(int *array, int size) {
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	_mergeSort(array, temp, size);
	free(temp);
}
