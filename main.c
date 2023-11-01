#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./utils/dataGenerator.c"
#include "./sortingAlgorithms/sorting.c"

void printArray(int *arr, int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", *(arr+i));
    printf("\n");
}


int main() {
    
    clock_t start, end; 


    // find a way to generate dynamic data as input
    int* arr = generateRandomData(100000);

    // for (int i = 0; i < 50; i++)
    // {
    //     printf(" %d ", arr[i]);
    // }
    
    start = clock();
 
    bubbleSort(arr, 100000);
 
    end = clock();

    // time in seconds
    double a = ((double)(end - start) / CLOCKS_PER_SEC); 

    printf("array sorted in: %fs\n", a);

    free(arr);

    return 0;
}
