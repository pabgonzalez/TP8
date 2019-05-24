/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: HP
 *
 * Created on May 23, 2019, 2:40 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "funbits.h"



int main (void) {
    //puerto.D.port = 0x32;
    puerto.B.byte = 32;
    puerto.A.byte = 0;
    bitClr(&(puerto.B), 5);
    bitSet(&(puerto.A) , 15);
    printf("%d\n", puerto.D.word);        
    return 0;
}
