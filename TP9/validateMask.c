/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include "funbits.h"
int bitGet(char port, int bit);
static int validateMask(char port, uint16_t mask);

int bitGet(char port, int bit){
    int ans;
    if(validate(port, bit)){
        ans = 0;
        return ans;
    }
    switch(port){
        case 'A':
            mask8 = (MASK1 << bit);
            puerto.A.byte &= mask8;
            ans = ((puerto.A.byte)>> bit);
            break;
        case 'B':
            mask8 = (MASK1 << bit);
            puerto.B.byte &= mask8;
            ans = ((puerto.B.byte)>> bit);
            break;
        case 'D':
            mask16 = (MASK1 << bit);
            puerto.D.word &= mask8;
            ans = ((puerto.D.word)>> bit);
            break;
        default: printf("Ingrese un puerto valido\n");  break;
    }
    
    return ans;
}

static int validateMask(char port, uint16_t mask){
    
    switch (port) {
        
        case 'A':
            if (mask >= 256){
                printf("Ingrese una mascara valida de 8 bits -A-\n");
                return 1;
            } 
            break;
            
        case 'B': 
            if (mask >= 256){
                printf("Ingrese una mascara valida de 8 bits -B-\n");
                return 1;
            } 
            break;
            
        case 'D':
            break;
        
        default: 
            printf("Ingrese un puerto valido\n");
            return 1;
            break;
    }
    return 0;
}