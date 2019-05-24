/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "funbits.h"

#define MASK1       0x1
#define BYTE    8

typedef union{
        struct {
            uint8_t b0 :1;
            uint8_t b1 :1;
            uint8_t b2 :1;
            uint8_t b3 :1;
            uint8_t b4 :1;
            uint8_t b5 :1;
            uint8_t b6 :1;
            uint8_t b7 :1;
        };
        uint8_t byte;
    } PORT_8bit;
    
    typedef union{
        struct {
            uint16_t b0          :1;
            uint16_t b1          :1;
            uint16_t b2          :1;
            uint16_t b3          :1;
            uint16_t b4          :1;
            uint16_t b5          :1;
            uint16_t b6          :1;
            uint16_t b7          :1;
            uint16_t b8          :1;
            uint16_t b9          :1;
            uint16_t b10         :1;
            uint16_t b11         :1;
            uint16_t b12         :1;
            uint16_t b13         :1;
            uint16_t b14         :1;
            uint16_t b15         :1;
        };
        uint16_t word;
    } PORT_16bit;
   
typedef union {
    struct {
        PORT_8bit B;
        PORT_8bit A;
    };
    PORT_16bit D;
        
}PORTS;

static int validate(char puerto, int bit);


static PORTS puerto;
static uint8_t mask8;
static uint16_t mask16;
    

void bitSet (char port, int bit){
    if (validate(port,bit))
        return;

    switch (port) {
        
        case 'A':
                mask8 = (MASK1 << bit);
                puerto.A.byte |= mask8;
            break;
            
        case 'B': 
                mask8 = (MASK1 << bit);
                puerto.B.byte |= mask8;
            break;
            
        case 'D':
                mask16 = (MASK1 << bit);
                puerto.D.word |= mask16;
            break;
        
        default: 
            printf("Ingrese un puerto valido\n");
            break;
    }
    return;
}
    


void bitClr (char port, int bit){
    if (validate(port,bit))
        return;

    switch (port) {
        
        case 'A':
                mask8 = ~(MASK1 << bit);
                puerto.A.byte &= mask8;
            break;
            
        case 'B': 
                mask8 = ~(MASK1 << bit);
                puerto.B.byte &= mask8;
            break;
            
        case 'D':
                mask16 = ~(MASK1 << bit);
                puerto.D.word &= mask16;
            break;
        
        default: 
            printf("Ingrese un puerto valido\n");
            break;
    }
    return;
}

void bitToggle (char port, int bit){
    if (validate(port,bit))
        return;

    switch (port) {
        
        case 'A':
                mask8 = (MASK1 << bit);
                puerto.A.byte ^= mask8;
            break;
            
        case 'B': 
                mask8 = (MASK1 << bit);
                puerto.B.byte ^= mask8;
            break;
            
        case 'D':
                mask16 = (MASK1 << bit);
                puerto.D.word ^= mask16;
            break;
        
        default: 
            printf("Ingrese un puerto valido\n");
            break;
    }
    return;
}



static int validate (char port, int bit){
    if (bit < 0){
        printf("El numero de bits no puede ser negativo\n");
        return 1;
    }
    
    switch (port) {
        
        case 'A':
            if (bit >= BYTE){
                printf("Ingrese un numero entre 0 y 7 -A-\n");
                return 1;
            } 
            break;
            
        case 'B': 
            if (bit >= BYTE){
                printf("Ingrese un numero entre 0 y 7 -B-\n");
                return 1;
            } 
            break;
            
        case 'D':
            if (bit >= 2*BYTE){
                printf("Ingrese un numero entre 0 y 15 -D-\n");
                return 1;
            }
            break;
        
        default: 
            printf("Ingrese un puerto valido\n");
            return 1;
            break;
    }
    return 0;
}