/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "funbits.h"
#include "simulador.h"

enum states {INIT, NEG, TURNON, TURNOFF, QUIT, ERROR};

static void turn_on(void);
static void turn_off(void);
static void negate(void);
static void printLeds(void);
static void cleanBuffer(void);

void simulate(void){
    char input = '0';
    int state = INIT;
    while((input = getchar())!= 'q'){
        cleanBuffer();
        if((input <= '7') && (input >= '0')){
            bitToggle('A',(input - '0' ));
        }
        else if(input == 'c'){
            turn_off();
        }
        else if(input == 's'){
            turn_on();
        }
        else if(input == 't'){
            negate();
        }
        else{
            printf("Operacion Invalida\n");
        }
    }
    printf("Fin de la simulacion\n");
    cleanBuffer();
    return;
}

static void turn_on(void){
    printf("Turn on!\n");
    return;
}

static void turn_off(void){
    printf("Turn off!\n");
    return;
}
static void negate(void){
    printf("Negate!\n");
    return;
}
static void printLeds(void){
    printf("Print Leds!\n");
    return;
}

static void cleanBuffer(void){
    while(getchar() != '\n'){}
    return;
}