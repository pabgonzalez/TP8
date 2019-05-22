/* 
 * File:   main.c
 * Author: Pablo
 *
 * Created on 22 de mayo de 2019, 12:01
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


    
    typedef struct {
        uint8_t b0          :1;
        uint8_t b1          :1;
        uint8_t b2          :1;
        uint8_t b3          :1;
        uint8_t b4          :1;
        uint8_t b5          :1;
        uint8_t b6          :1;
        uint8_t b7          :1;
    } PUERTO_bit;

    typedef struct {
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
    }PUERTO_2bit;
    
   
typedef union {
    struct {
        PUERTO_bit A;
        PUERTO_bit B;
    }AB;
    PUERTO_2bit D;
        
}PUERTOS;
    
    
int main (void) {
    PUERTOS puertos;
    
    //puertos.AB.A.b1 = 1;
    //printf("%c", puertos.AB.A.b0);
    return 0;
}
    
*/

int main(void){
    printf("%d", 2);
    return 0;
}