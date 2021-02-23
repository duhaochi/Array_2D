//
//  412_lab_4.c
//  Array_2D
//
//  Created by duhaochi on 2/22/21.
//

#include <stdio.h>
#include <stdlib.h>

#include "412_lab_4.h"
#include "Darray.h"
typedef struct Words{
    int length;
    char *type;
    Darray array;
    
}words;
void openFile(char const *name, words *wordStruct);
void readWordsFile(FILE *name, words *wordStruct);

int main(int argc, const char * argv[]){
    words *word = malloc(sizeof(struct Words));

    FILE * fp;
    fp = fopen ("data2.txt", "w+");
    
    int num;
    fscanf(fp, "%d", &num);
    printf("got %d\n", num);
    
    openFile("/test1.txt", word);
    printf("array at 0 = %s\n", (char *)arrayGet(word->array, 0));
    printf("array length = %d\n", arrayLength(word->array));
}

void openFile(char const *name, words *wordStruct){
    FILE *fp = fopen("data2.txt", "r+");
    
    if (fp == NULL){
        printf("failed \n");
        exit(0);
    }
    
    readWordsFile(fp, wordStruct);
    fclose(fp);
}

void readWordsFile(FILE *name, words *wordStruct){
    int num;
    char *word = malloc(sizeof(char *));
    fscanf(name, "%d", &num);
    printf("%d\n", num);
    wordStruct->array = arrayNew(num, sizeof(void*));
    char *str = arrayGet(wordStruct->array, 0);
}
