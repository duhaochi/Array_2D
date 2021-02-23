//
//  Darray.h
//  Array_2D
//
//  Created by duhaochi on 2/21/21.
//

#ifndef Darray_h
#define Darray_h

#include <stdio.h>
#define D Darray
typedef struct D *D;

/*
 I consider this interface to be client friendly, instead of changing the struct array directlly in
 client code, it forces you to use the method it provide. I say force because if is imposiable to access the struct directly inside client code, due to it's *D nature.
 to achive polymorphism I used a void* array, you can cast it into any type you want. It is just a block of sequential memory and array is simply the beginning of that block of memory.
 */


struct D{
    int length;
    int size;
    void *array;
};

D arrayNew(int length, int size);
void arrayPopulate(D array);
/* since there is no way the interface can find out the
 type, I used memcpy() here to assig values */

//ofcouce this's have to check for buffer overflow!!!
void arrayPut(D arr, int i, void* ele);

int arrayLength(D arr);
/*
 returns the element at i, mainly doing pointer math in the implementation.
 */
void *arrayGet(D arr, int i);

/*
 iterate throught the array and call apply on each element with it;s index and a closure.
 */
void array_map(D array, void apply(void** sbj, void* ele, void* cl), void* cl);

void array_free(D *darray);
#endif /* Darray_h */
