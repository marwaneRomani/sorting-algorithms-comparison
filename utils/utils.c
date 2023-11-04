#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

#define PI 3.14159265358979323846


#define PI 3.14159265358979323846


/**
 * generateSortedData - Function that generate sorted data
 *
 * @limit: size of data to generate by this function
 * Return: array of data
 */
int* generateSortedData(int limit) {
    
    int *data = malloc(sizeof(int) * limit);

    for (int i = 0; i < limit; i++)
        data[i] = i + 1;


    return data;
}

/**
 * generateReversedSortedData - Function that revesed data
 *
 * @limit: size of data to generate by this function
 * Return: array of data
 */
int* generateReversedSortedData(int limit) {
    
    int *data = malloc(sizeof(int) * limit);

    for (int i = 0, j = limit - 1; i < limit; i++, j--)
        data[i] = j;

    return data;
}

/**
 * generateRandomData - Function that generete random data
 *
 * @limit: size of data to generate by this function
 * Return: array of data
 */
int* generateRandomData(int limit) {
    
    int *data = malloc(sizeof(int) * limit);

    for (int i = 0, j = limit - 1; i < limit; i++, j--)
        data[i] = rand();

    return data;
}

double gaussianWeight(double x, double sigma) {
    return (1.0 / (sqrt(2 * PI) * sigma)) * exp(- (x * x) / (2 * sigma * sigma));
}

double gaussienNormalization() {
    double sigma = 1.0;
    int windowSize = 3;
    int kernelRadius = windowSize / 2;
    double kernel[windowSize];
    double total = 0.0;

    // calculate the weights (-1,0 and 1)
    for (int i = -kernelRadius; i <= kernelRadius; i++) {
        kernel[i + kernelRadius] = gaussianWeight(i, sigma);
        total += kernel[i + kernelRadius];
    }
    
    return total;
}

double convolution(double priviousTime, double time, double nextTime) {
    double newTime = (gaussianWeight(-1, 1) * priviousTime + gaussianWeight(0, 1) * time + gaussianWeight(1, 1) * nextTime) / gaussienNormalization();

    return newTime;
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

/**
 * heapify - Recursive function to sort binary tree
 * @array: array to be sorted as binary tree
 * @end: Last node in binary tree
 * @start: First node of binary tree
 * @size: Size of the array to sort
 * Return: 0
 */
void heapify(int *array, int end, int start, int size)
{
	int max = start;
	int left = 2 * start + 1;
	int right = 2 * start + 2;

	if (!array || size < 2)
		return;

	if (left < end && array[left] > array[max])
		max = left;

	if (right < end && array[right] > array[max])
		max = right;

	if (start != max)
	{
		swap(&array[start], &array[max]);
		
		heapify(array, end, max, size);
	}
}