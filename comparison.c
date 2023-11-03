#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparison.h"
#include "./sortingAlgorithms/sorting.h"
#include "./utils/dataGenerator.h"


// int sizes[] = { 1000,2000,4000, 8000, 16000, 32000, 64000, 128000 };


void sortedArrayInput() {
    int sizesCount = sizeof(INPUT_SIZES)/sizeof(INPUT_SIZES[0]);

    // array of function pointers //
    void (*methods[])(int*, int) = { selectionSort };

    // a loop on different input sizes //
    for (int i = 0; i < sizesCount; i++) {

//        printf("generating data...\n");      
        int *data = generateSortedData(INPUT_SIZES[i]);
        
        // sorting data and bench marking 
        int methodsCount = sizeof(methods) / sizeof(methods[0]);

        for (int j = 0; j < methodsCount; j++) {
            clock_t start, end;

            start = clock();
            methods[j](data, INPUT_SIZES[i]);       
            end = clock();
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            printf("%d\t%d\t%lf\n", j, INPUT_SIZES[i], a);
        }
        
        // printf("------------------ next size ------------------------\n\n");
    }    
}

void reversedArrayInput() {
    int sizesCount = sizeof(INPUT_SIZES)/sizeof(INPUT_SIZES[0]);


    // array of function pointers
    void (*methods[])(int*, int) = { bubbleSort };

    //a loop on different input sizes
    for (int i = 0; i < sizesCount; i++) {

        printf("generating data...\n");      
        int *data = generateReversedSortedData(INPUT_SIZES[i]);
        
        // sorting data and bench marking 
        int methodsCount = sizeof(methods) / sizeof(methods[0]);

        for (int j = 0; j < methodsCount; j++) {
            clock_t start, end;

            start = clock();
            methods[j](data, INPUT_SIZES[i]);       
            end = clock();
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            printf("method %d takes to sort an array of size %d : %lf \n", j, INPUT_SIZES[i], a);
        }
        
        printf("------------------ next size ------------------------\n\n");
    }
}

void randomArrayInput() {
    int sizesCount = sizeof(INPUT_SIZES)/sizeof(INPUT_SIZES[0]);


    // array of function pointers
    void (*methods[])(int*, int) = { bubbleSort };

    //a loop on different input sizes
    for (int i = 0; i < sizesCount; i++) {

        printf("generating data...\n");      
        int *data = generateRandomData(INPUT_SIZES[i]);
        
        // sorting data and bench marking 
        int methodsCount = sizeof(methods) / sizeof(methods[0]);

        for (int j = 0; j < methodsCount; j++) {
            clock_t start, end;

            start = clock();
            methods[j](data, INPUT_SIZES[i]);       
            end = clock();
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            printf("method %d takes to sort an array of size %d : %lf \n", j, INPUT_SIZES[i], a);
        }
        
        printf("------------------ next size ------------------------\n\n");
    }
}