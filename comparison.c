#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./sortingAlgorithms/sorting.c"


int sizes[] = { 1000, 5000, 25000, 100000, 500000 };

//int sizes[] = { 10 };

void sortedArrayInput() {
    int sizesCount = sizeof(sizes)/sizeof(sizes[0]);


    // array of function pointers
    void (*methods[])(int*, int) = { bubbleSort };

    //a loop on different input sizes
    for (int i = 0; i < sizesCount; i++) {

        printf("generating data...\n");      
        int *data = generateSortedData(sizes[i]);
        
        // sorting data and bench marking 
        int methodsCount = sizeof(methods) / sizeof(methods[0]);

        for (int j = 0; j < methodsCount; j++) {
            clock_t start, end;

            start = clock();
            methods[j](data, sizes[i]);       
            end = clock();
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            printf("method %d takes to sort an array of size %d : %lf \n", j, sizes[i], a);
        }
        
        printf("------------------ next size ------------------------\n\n");
    }
}

void reversedArrayInput() {
    int sizesCount = sizeof(sizes)/sizeof(sizes[0]);


    // array of function pointers
    void (*methods[])(int*, int) = { bubbleSort };

    //a loop on different input sizes
    for (int i = 0; i < sizesCount; i++) {

        printf("generating data...\n");      
        int *data = generateReversedSortedData(sizes[i]);
        
        // sorting data and bench marking 
        int methodsCount = sizeof(methods) / sizeof(methods[0]);

        for (int j = 0; j < methodsCount; j++) {
            clock_t start, end;

            start = clock();
            methods[j](data, sizes[i]);       
            end = clock();
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            printf("method %d takes to sort an array of size %d : %lf \n", j, sizes[i], a);
        }
        
        printf("------------------ next size ------------------------\n\n");
    }
}

void randomArrayInput() {
    int sizesCount = sizeof(sizes)/sizeof(sizes[0]);


    // array of function pointers
    void (*methods[])(int*, int) = { bubbleSort };

    //a loop on different input sizes
    for (int i = 0; i < sizesCount; i++) {

        printf("generating data...\n");      
        int *data = generateRandomData(sizes[i]);
        
        // sorting data and bench marking 
        int methodsCount = sizeof(methods) / sizeof(methods[0]);

        for (int j = 0; j < methodsCount; j++) {
            clock_t start, end;

            start = clock();
            methods[j](data, sizes[i]);       
            end = clock();
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            printf("method %d takes to sort an array of size %d : %lf \n", j, sizes[i], a);
        }
        
        printf("------------------ next size ------------------------\n\n");
    }
}