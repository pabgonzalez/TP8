/***************************************************************************//**
  @file     +funbits.c+
  @brief    +Contiene funciones para el manejo de los puertos A, B y D+
            +A y B son puertos de 8 bits mientras que D es de 16 bits (A y B juntos).
  @author   +Grupo 2+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "funbits.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/
#define MASK1   0x1
#define BYTE    8

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/
   
typedef union {
    struct {
        uint8_t B;
        uint8_t A;
    };
    uint16_t D;       
}PORT;


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
static int validate(char puerto, int bit);
static int validateMask(char port, uint16_t mask);

/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/
static PORT puerto;
static uint8_t mask8;
static uint16_t mask16;
    
/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/
void bitSet (char port, int bit){
    if (validate(port,bit))             //Sigue si la entrada es válida,                              
        return;

    switch (port) {
        
        case 'A':                       //Caso Puerto A                
            mask8 = (MASK1 << bit);     //Crea una máscara que solo tiene un 1 en la posición recibida.
            puerto.A |= mask8;     //
            break;
            
        case 'B': 
            mask8 = (MASK1 << bit);
            puerto.B |= mask8;
            break;
            
        case 'D':
            mask16 = (MASK1 << bit);
            puerto.D |= mask16;
            break;
        
        default: 
            printf("default\n");
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
            puerto.A &= mask8;
            break;
            
        case 'B': 
            mask8 = ~(MASK1 << bit);
            puerto.B &= mask8;
            break;
            
        case 'D':
            mask16 = ~(MASK1 << bit);
            puerto.D &= mask16;
            break;
        
        default: 
            printf("default\n");
            break;
    }
    return;
}

int bitGet(char port, int bit){
    int ans;
    if(validate(port, bit)){
        return -1;
    }
    switch(port){
        case 'A':
            mask8 = (MASK1 << bit);
            puerto.A &= mask8;
            ans = ((puerto.A)>> bit);
            break;
        case 'B':
            mask8 = (MASK1 << bit);
            puerto.B &= mask8;
            ans = ((puerto.B)>> bit);
            break;
        case 'D':
            mask16 = (MASK1 << bit);
            puerto.D &= mask8;
            ans = ((puerto.D)>> bit);
            break;
        default: printf("Ingrese un puerto valido\n");  break;
    }
    
    return ans;
}

void bitToggle (char port, int bit){
    if (validate(port,bit))
        return;

    switch (port) {
        
        case 'A':
            mask8 = (MASK1 << bit);
            puerto.A ^= mask8;
            break;
            
        case 'B': 
            mask8 = (MASK1 << bit);
            puerto.B ^= mask8;
            break;
            
        case 'D':
            mask16 = (MASK1 << bit);
            puerto.D ^= mask16;
            break;
        
        default: 
            printf("default\n");
            break;
    }
    return;
}

void maskOn (char port, uint16_t mask) { 
    if (validateMask(port,mask))
        return;
    
    switch (port) {
        case 'A':
            puerto.A |= (uint8_t)mask;
            break;
        case 'B': 
            puerto.B |= (uint8_t)mask;
            break;
        case 'D':
            puerto.D |= mask;
            break;
        default:
            printf("default\n");
            break;               
    }
    return;
}

void maskOff (char port, uint16_t mask) { 
    if (validateMask(port,mask))
        return;
    
    switch (port) {
        case 'A':
            puerto.A &= ~(uint8_t)mask;
            break;
        case 'B': 
            puerto.B &= ~(uint8_t)mask;
            break;
        case 'D':
            puerto.D &= ~mask;
            break;
        default:
            printf("default\n");
            break;               
    }
    return;
}

void maskToggle (char port, uint16_t mask) { 
    if (validateMask(port,mask))
        return;
    
    switch (port) {
        case 'A':
            puerto.A ^= (uint8_t)mask;
            break;
        case 'B': 
            puerto.B ^= (uint8_t)mask;
            break;
        case 'D':
            puerto.D ^= mask;
            break;
        default:
            printf("default\n");
            break;               
    }
    return;
}

/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

/* validate:    recibe un puerto y un bit. verifica la validez del número de bit 
                para ese puerto. Devuelve un 0 si es valido y un 1 sino. 
 */
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
            printf("default\n");
            return 1;
            break;
    }
    return 0;
}

/* validateMask:    recibe un puerto y una máscara de 16 bits. Valida que el 
 *                  tamaño la máscara sea compatible con ese puerto. 
 *                  Devuelve un 0 si lo es y un 1 sino.
 */
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
            printf("default\n");
            return 1;
            break;
    }
    return 0;
}

/*******************************************************************************
 ******************************************************************************/