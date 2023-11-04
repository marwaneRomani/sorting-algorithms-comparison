#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int* generateSortedData(int limit) {
    
    int *data = malloc(sizeof(int) * limit);

    for (int i = 0; i < limit; i++)
        data[i] = i + 1;


    return data;
}

int* generateReversedSortedData(int limit) {
    
    int *data = malloc(sizeof(int) * limit);

    for (int i = 0, j = limit - 1; i < limit; i++, j--)
        data[i] = j;

    return data;
}


int* generateRandomData(int limit) {
    
    int *data = malloc(sizeof(int) * limit);

    for (int i = 0, j = limit - 1; i < limit; i++, j--)
        data[i] = rand();

    return data;
}

/**
 * swap - Function that swaps two values
 *
 * @a: Fisrt value
 * @b: Second value
 * Return: 0
 */
void swap(int *a, int *b) {
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

/**
 * partition - Function that sets the pivot for quick_sort
 *
 * @array: Array to partition
 * @size: Size of array
 * Return: (i + 1)
 */
int partition(int array[], int size)
{
	int pivot;
	int i = -1;
	int j;

	if (!array || size < 2)
		return (0);

	pivot = array[size - 1];

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
			}
		}
	}
	if (i + 1 != size - 1)
	{
		swap(&array[i + 1], &array[size - 1]);
	}
	return (i + 1);
}