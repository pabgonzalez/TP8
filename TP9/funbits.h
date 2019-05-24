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

void bitSet (char puerto, int bit);        //Dado un puerto y un número de bit, lo setea en 1.
void bitClr (char  puerto, int bit);        //Dado un puerto y un número de bit, lo setea en 0.
int bitGet(char port, int bit);
void bitToggle (char port, int bit);
void maskOn (char port, uint16_t mask);
void maskOff (char port, uint16_t mask);
void maskToggle (char port, uint16_t mask);


#endif /* FUNBITS_H */

