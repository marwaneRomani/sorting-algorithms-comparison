#include <stdio.h>
#include <stdlib.h>

int* generateSortedData(int limit) {
    
    int *data = malloc(sizeof(int) * limit);

    for (int i = 0; i < limit; i++)
        data[i] = i + 1;

    // for (int i = 0; i < limit - 1; i++)
    //     printf("%d\n",data[i]);


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
