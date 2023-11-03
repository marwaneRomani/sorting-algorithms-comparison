#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparison.h"
#include "./sortingAlgorithms/sorting.h"
#include "./utils/utils.h"


void sortedArrayInput() {

    int start = 100;
    int increment = 100;
    int end = 100000;
    int size = (end - start) / increment + 1; // +1 to include the start value
    int inputSizes[size];

    for (int i = 0; i < size; ++i) {
        inputSizes[i] = start + i * increment;
    }
    int sizesCount = sizeof(inputSizes)/sizeof(inputSizes[0]);

    // array of function pointers //
    void (*methods[])(int*, int) = { selectionSort };

    // a loop on different input sizes //
    for (int i = 0; i < sizesCount; i++) {

//        printf("generating data...\n");      
        int *data = generateSortedData(inputSizes[i]);
        
        // sorting data and bench marking 
        int methodsCount = sizeof(methods) / sizeof(methods[0]);

        for (int j = 0; j < methodsCount; j++) {
            clock_t start, end;

            start = clock();
            methods[j](data, inputSizes[i]);       
            end = clock();
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            printf("%d\t%d\t%lf\n", j, inputSizes[i], a);
        }

        // printf("------------------ next size ------------------------\n\n");
    }    
}

void reversedArrayInput() {
//    int sizesCount = sizeof(sizes)/sizeof(sizes[0]);


//     // array of function pointers
//     void (*methods[])(int*, int) = { bubbleSort };

//     //a loop on different input sizes
//     for (int i = 0; i < sizesCount; i++) {

        // printf("generating data...\n");      
        // int *data = generateReversedSortedData(sizes[i]);
        
//         // sorting data and bench marking 
//         int methodsCount = sizeof(methods) / sizeof(methods[0]);

//         for (int j = 0; j < methodsCount; j++) {
//             clock_t start, end;

            // start = clock();
            // methods[j](data, sizes[i]);       
            // end = clock();
            
//             double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            // printf("method %d takes to sort an array of size %d : %lf \n", j, sizes[i], a);
        }

void randomArrayInput() {
    // int sizesCount = sizeof(sizes)/sizeof(sizes[0]);


//     // array of function pointers
//     void (*methods[])(int*, int) = { bubbleSort };

//     //a loop on different input sizes
//     for (int i = 0; i < sizesCount; i++) {

//         printf("generating data...\n");      
//         int *data = generateRandomData(sizes[i]);
        
//         // sorting data and bench marking 
//         int methodsCount = sizeof(methods) / sizeof(methods[0]);

//         for (int j = 0; j < methodsCount; j++) {
//             clock_t start, end;

            // start = clock();
            // methods[j](data, sizes[i]);       
            // end = clock();
            
//             double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            // printf("method %d takes to sort an array of size %d : %lf \n", j, sizes[i], a);
        }
