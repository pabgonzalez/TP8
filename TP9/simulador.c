/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include "funbits.h"
#include "simulador.h"

#define BYTE 8

enum states {INIT, NEG, TURNON, TURNOFF, QUIT, ERROR};

static void turn_on(void);
static void turn_off(void);
static void negate(void);
void printLeds(void);
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
        printLeds();
    }
    printf("Fin de la simulacion\n");
    cleanBuffer();
    return;
}

static void turn_on(void){
    printf("Turn on!\n");
    maskOn('A', 0xFF);
    return;
}

static void turn_off(void){
    printf("Turn off!\n");
    maskOff('A', 0xFF);
    return;
}
static void negate(void){
    printf("Negate!\n");
    maskToggle('A', 0xFF);
    return;
}
void printLeds(void){
    int i;
    printf("-----------------\n");
    printf("|     PORTA     |\n");
    printf("-----------------\n");
    putchar('|');
    for(i = 0; i < BYTE; i++){
        if(bitGet('A', i)){
            putchar('*');
        }
        else{
            putchar(' ');
        }
        putchar('|');
    }
    putchar('\n');
    printf("-----------------\n");
    return;
}

static void cleanBuffer(void){
    while(getchar() != '\n'){}
    return;
}