#include "lista_enlazada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


lista_t* nueva_lista(void) {
   lista_t *puntero = malloc(sizeof(lista_t));
   puntero -> head = NULL;
   return puntero;

}

uint32_t longitud(lista_t* lista) {
    uint32_t count = 0;
    if (lista != NULL && lista->head != NULL) {
         nodo_t *nodo = lista->head;                    
         while (nodo != NULL){
            nodo = nodo->next;
            count ++;
         }
    }
    return count;

}

void agregar_al_final(lista_t* lista, uint32_t* arreglo, uint64_t largo) {
    nodo_t *ultimo_nodo = iesimo(lista, longitud(lista) - 1);

    uint32_t *copia_arreglo = malloc(sizeof(uint32_t) * largo);
    for (uint32_t i=0; i < largo; i++) {                          
        copia_arreglo[i] = arreglo[i];
    }

    nodo_t *ultimo = malloc(sizeof(nodo_t));
    ultimo_nodo->next = ultimo;

    nodo_t *nuevo_nodo = ultimo_nodo->next;
    nuevo_nodo->arreglo = copia_arreglo;
    nuevo_nodo->longitud = largo;
    nuevo_nodo->next = NULL;
}

nodo_t* iesimo(lista_t* lista, uint32_t i) {

    uint32_t count = 0;
    nodo_t *nodo = lista ->head;
    if (longitud(lista) != 0){
        while (i != count) {
            nodo = nodo ->next;
            count++;
        }
    }
    return nodo;

}

uint64_t cantidad_total_de_elementos(lista_t* lista) {
    uint64_t elementos = 0;
    nodo_t *nodo = lista -> head;
    while (nodo != NULL){
        elementos += nodo -> longitud;
        nodo = nodo -> next;
    }
    return elementos;
}

void imprimir_lista(lista_t* lista) {
    if (longitud(lista) == 0) {                  
        printf("null");
    }
    nodo_t *nodo = lista -> head;
    while (nodo != NULL) {
        printf("|%lu|->",nodo->longitud);           
        nodo = nodo -> next;
    }

}


int array_contiene_elemento(uint32_t* array, uint64_t size_of_array, uint32_t elemento_a_buscar){
    uint32_t i = 0;
    uint64_t contador = 0;
    while (contador < size_of_array){
        if (array[i] == elemento_a_buscar) {
            return 1;
        } else {
          contador++;
          i++;
        }
    }
    return 0;
}


int lista_contiene_elemento(lista_t* lista, uint32_t elemento_a_buscar) {
    nodo_t *nodo = lista -> head;
    while (nodo != NULL) {
        if (array_contiene_elemento(nodo->arreglo,nodo->longitud,elemento_a_buscar) == 1){
            return 1;
        } else {
            nodo = nodo -> next;
        }
    }
    return 0;
}

nodo_t *destruir_nodo(nodo_t* nodo){
    nodo_t *limpio = nodo -> next;
    free(nodo);
    free(nodo -> arreglo);
    return limpio;
}

// Devuelve la memoria otorgada para construir la lista indicada por el primer argumento.
// Tener en cuenta que ademas, se debe liberar la memoria correspondiente a cada array de cada elemento de la lista.
void destruir_lista(lista_t* lista) {
    if (lista != NULL) {
        nodo_t *nodo = lista ->head;
        while (nodo != NULL){
            // nodo = nodo -> next;
            // iteremos en nodos
            nodo = destruir_nodo(nodo);
        }
        free(nodo);
    }
    
}