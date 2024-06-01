#include <stdio.h>
#include <stdlib.h>

typedef struct dynamic {
    int row; 
    int col;
    int** array;
} dynamic;

void print(dynamic* a){
    for(int i = 0; i < a->row; i++){
        for(int j = 0; j < a->col; j++){
            printf("%d", a->array[i][j]);
        }
        printf("\n");
    }
}

dynamic* generate(int row, int col){
    dynamic* result = (dynamic*)malloc(sizeof(dynamic));
    result->col = col; 
    result->row = row;
    int** temp = (int**)calloc(row, sizeof(int*));
    for(int i = 0; i < row; i++){
        temp[i] = (int*)calloc(col, sizeof(int));
    }
    result->array = temp; 
    return result; 
}

dynamic* matrixmul(dynamic* first, dynamic* second){
    if(first->col != second->row){
        printf("wrong size");
        return NULL; 
    }
    dynamic* result = (dynamic*)malloc(sizeof(dynamic));
    result = generate(first->row, second->col);
    int sum = 0;
    for(int i = 0; i < first->row; i++){
        for(int j = 0; j < second->col; j++){
            sum = 0;
            for(int k = 0; k < first->col; k++){
                sum += first->array[i][k] * second->array[k][j];
            }
            result->array[i][j] = sum;
        }
    }
    return result;
} 