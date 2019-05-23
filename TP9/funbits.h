/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   funbits.h
 * Author: HP
 *
 * Created on May 23, 2019, 8:39 PM
 */

#ifndef FUNBITS_H
#define FUNBITS_H

void bitSet (void* puerto, int bit);        //Dado un puerto y un número de bit, lo setea en 1.
void bitClr (void* puerto, int bit);        //Dado un puerto y un número de bit, lo setea en 0.

#define MASK1   0x1
#define MAX_BYTE   8

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
        uint8_t port;
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
        uint16_t port;
    } PORT_16bit;
   
typedef union {
    struct {
        PORT_8bit B;
        PORT_8bit A;
    };
    PORT_16bit D;
        
}PORTS;

#endif /* FUNBITS_H */

