#include "array_dinamico.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    ArrayDinamico* array = array_dinamico_create();

    for(int i = 0; i < 15; i++){
        array_dinamico_add(array, i);
    }

    array_dinamico_print(array);
    
    return 0;
}