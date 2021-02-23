//
//  main.c
//  Array_2D
//
//  Created by duhaochi on 2/21/21.
//

#include <stdio.h>
#include "Darray.h"

//___________function Declaration___________
void appendZeros(void** ele, void* index, void* cl);
void printArray(void** ele, void* index, void* cl);


//___________body of main___________
int mains(int argc, const char * argv[]) {
    // insert code here...
    
    D arr;
    arr = arrayNew(3, sizeof(int));
    
    //0. way to put elements in array by map the whole array.
    array_map(arr, appendZeros, NULL);
    
    //1. way to put num in array index 0, although this is a implementated feature but it is
    // not recommended, the implementation considered to be unsafe.
    int num = 8;
    arrayPut(arr, 0, &num);
    
    //2. way to put num in array is by dereference it by the know type, then assign values to it
    int *ele = arrayGet(arr, 2);
    *ele = 200;
    
    //printing the result, which should be 100, 0, 200
    array_map(arr, printArray, NULL);
    
    array_free(&arr);
    array_map(arr, printArray, NULL);
    printf("END\n");
    return 0;
}



//below are two example apply functions
void appendZeros(void** ele, void* index, void* cl){
    (void) cl;
    int zero = 0;
    int* num = (int *) ele;
    *num = zero;
}

void printArray(void** ele, void* index, void* cl){
    (void) cl;
    int* num = (int *) ele;
    printf("%d ", *num);
}
