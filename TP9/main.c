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
    PORTS puerto;
    puerto.D.port = 96;
    puerto.B.b0 = 1;
    bitClr(&(puerto.B), 0);
    printf("%i", puerto.D.port);        
    return 0;
}
