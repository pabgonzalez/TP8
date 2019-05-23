/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "funbits.h"


void bitSet (void* puerto, int bit){
    if ((bit < 0) || (bit >= 2*MAX_BYTE)){
        printf("Ingrese un valor valido\n");
        return;
    }
    char* byte = puerto;
    char x;
       
    if (bit >= MAX_BYTE){
        bit -= MAX_BYTE;
        x = MASK1 << bit;
        *(byte+1) = *(byte+1)| x;
    }
    else{
        x = MASK1 << bit;
        *byte = *byte | x;
    }
    
    return;    
}

void bitClr (void* puerto, int bit){
    if ((bit < 0) || (bit >= 2*MAX_BYTE)){
        printf("Ingrese un valor valido\n");
        return;
    }
    char* byte = puerto;
    char x;
       
    if (bit >= MAX_BYTE){
        bit -= MAX_BYTE;
        x = ~(MASK1 << bit);
        *(byte+1) = *(byte+1)& x;
    }
    else{
        x = ~(MASK1 << bit);
        *byte = *byte & x;
    }
    
    return;    
}
