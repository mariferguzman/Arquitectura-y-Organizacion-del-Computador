#include "contar_espacios.h"
#include <stdio.h>

uint32_t longitud_de_string(char* string) {
    int count = 0;
    if(string == NULL) {
        return 0;
    } 
    for(int i = 0; ; i++) {
        if(string[i] == '\0') {
            return count;
        }   
        count++;
    }
}

uint32_t contar_espacios(char* string) {
    int count = 0;
    if(string == NULL) {
        return 0;
    }    
    for(int i = 0; ; i++) {
        if(string[i] == ' ') {
            count++;
        }    
        if(string[i] == '\0') {
            return count;
        }   
    }
}

