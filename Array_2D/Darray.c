//
//  Darray.c
//  Array_2D
//
//  Created by duhaochi on 2/21/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Darray.h"

#define D Darray

D arrayNew(int length, int size){
    D array;
    array = malloc(sizeof(struct Darray));
    arrayPopulate(array);
    array->length = length;
    array->size = size;
    return array;
}

void arrayPopulate(D arr){
    assert(arr);
    arr->array = calloc(arr->length, arr->size);
}

void arrayPut(D arr, int i, void* ele){
    void* loc = arrayGet(arr, i);
    assert(ele);
    memcpy(loc, ele, arr->size);
}

int arrayLength(D arr){
    return arr->length;
}


void *arrayGet(D arr, int i){
    void *array = arr->array + arr->size*i;
    return array;
}

void array_map(D array, void apply(void** ele, void* index, void* cl), void* cl){
    for(int i = 0; i < array->length; i++){
        void *elep = arrayGet(array, i);
        apply(elep, &i, cl);
    }
}

void array_free(D *darray){
    free((*darray)->array);
    free(*darray);
}
