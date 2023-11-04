#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"

#define PI 3.14159265358979323846


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