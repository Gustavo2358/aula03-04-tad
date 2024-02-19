#include "array_dinamico.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10;

typedef struct ArrayDinamico{
    Element* data;
    int size;
    int capacity;
} ArrayDinamico;

ArrayDinamico* array_dinamico_create(){
    ArrayDinamico* result = malloc(sizeof(ArrayDinamico));
    result-> capacity = INITIAL_CAPACITY;
    result->data = malloc(sizeof(Element) * result->capacity);
    result->size = 0;
    return result;
}

void array_dinamico_destroy(ArrayDinamico* array){
    free(array->data);
    free(array);
}

static void increase_capacity(ArrayDinamico* array){
    int size = array->size;
    int new_capacity = array->capacity * 2;
    Element* new_data_array = malloc(sizeof(Element) * new_capacity);
    
    for(int i = 0; i < size; i++){
        new_data_array[i] = array->data[i];
    }

    array->data = new_data_array;
    array->capacity = new_capacity;

}

void array_dinamico_add(ArrayDinamico* array, Element valor){
    int size = array->size;
    int capacity = array->capacity;
    if(size < capacity){
        array->data[size] = valor;
        array->size++;
    }
    else {
        increase_capacity(array);
        array->data[size] = valor;
        array->size++;
    }
}

void array_dinamico_print(ArrayDinamico* array){
    int size = array->size;
    for(int i = 0; i < size; i++){
        print_element(array->data[i]);
        
    }
    printf("\n");
}
int array_dinamico_size(ArrayDinamico* array);
void array_dinamico_set(ArrayDinamico* array, int pos, Element valor);
