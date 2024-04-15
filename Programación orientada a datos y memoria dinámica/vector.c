#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


vector_t* nuevo_vector(void) {
    vector_t *vector = malloc(sizeof(vector_t));
    vector -> size = 0;
    vector -> capacity = 2;
    uint32_t *arreglo = malloc(sizeof(uint32_t) * vector -> capacity);
    vector -> array = arreglo;

    return vector;
}

uint64_t get_size(vector_t* vector) {
    return vector -> size;
}

void push_back(vector_t* vector, uint32_t elemento) {
    if(vector->size == vector->capacity) {
        vector->capacity *= 2;
        vector->array = realloc(vector->array, sizeof(uint32_t) * vector->capacity);
    }

    //uint32_t *pos = (vector->array + (sizeof(uint32_t) * vector->size));
    vector->array[vector->size] = elemento;
    vector->size++;
}

int son_iguales(vector_t* v1, vector_t* v2) {
    if(get_size(v1) != get_size(v2)) {
        return 0;
    }

    for(uint32_t i = 0; i < get_size(v1); i++) {
        if((v1->array[i]) != (v2->array[i])) {
            return 0;
        }
    }

    return 1;
}

uint32_t iesimo(vector_t* vector, size_t index) {
    if(index >= get_size(vector)) {
        return 0;
    }

    return vector->array[index];
}

void copiar_iesimo(vector_t* vector, size_t index, uint32_t* out)
{
    *out = iesimo(vector, index);
}


// Dado un array de vectores, devuelve un puntero a aquel con mayor longitud.
vector_t* vector_mas_grande(vector_t** array_de_vectores, size_t longitud_del_array) {
    if(longitud_del_array == 0) {
        return NULL;
    }

    vector_t* mas_grande = NULL;
    for(size_t i = 0; i < longitud_del_array; i++) {
        vector_t* vector = array_de_vectores[i];
        if(get_size(vector) > get_size(mas_grande)) {
            mas_grande = vector;
        }
    }

    return mas_grande;
}
