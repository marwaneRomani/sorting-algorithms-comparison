#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparison.h"
#include "./sortingAlgorithms/sorting.h"
#include "./utils/utils.h"

void sortedArrayInput(int start, int increment, int end) {
    int size = (end - start) / increment + 1; // +1 to include the start value
    int inputSizes[size];

    for (int i = 0; i < size; ++i) {
        inputSizes[i] = start + i * increment;
    }

    int sizesCount = sizeof(inputSizes)/sizeof(inputSizes[0]);

    // array of function pointers //
    void (*methods[])(int*, int) = { selectionSort, bubbleSort, heapSort, insertionSort, quickSort, mergeSort };
    // void (*methods[])(int*, int) = { insertionSort };


    // sorting data and bench marking 
    int methodsCount = sizeof(methods) / sizeof(methods[0]);

    int results[methodsCount * sizesCount][2]; 
    double times[methodsCount * sizesCount]; 

    // a loop on different input sizes
    int linesCounter = 0;
    for (int i = 0; i < methodsCount; i++) {

        for (int j = 0; j < sizesCount; j++, linesCounter++) {

            int *data = generateSortedData(inputSizes[j]);    

            clock_t start, end;

            start = clock();
            methods[i](data, inputSizes[j]);       
            end = clock(); 
            
            double a = ((double)(end - start) / CLOCKS_PER_SEC);
            
            
            results[linesCounter][0] = i;
            results[linesCounter][1] = inputSizes[j];
            times[linesCounter] = a; 

            // printf("%d\t%d\t%lf\n", i, inputSizes[j], a);

        }
        
    }

    // apply curve smoothing and print changes
    int methodIndex = results[0][0];
    int currentMethod = 0;

    for (int i = 2; i < methodsCount * sizesCount - 1; i++) {
        //double res = convolution(times[i-1], times[i], times[i+1]);

        double total = 0.0;

        for (int j = currentMethod; j < i; j++) 
            total += times[j];      
        

        double res = total / i;

        printf("%d\t%d\t%lf\t\n", results[i][0], results[i][1], res);

        if (results[i+1][0] != methodIndex) {
            printf("\n\n\n\n");
            methodIndex = results[i+1][0];
            currentMethod = i;
        }
    }
    
}

void reversedArrayInput(int start, int increment, int end) {
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

void randomArrayInput(int start, int increment, int end) {
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
