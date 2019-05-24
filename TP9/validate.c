/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

static int validate(char puerto, int bit);

static int validate (char puerto, int bit){
    if (bit < 0){
        printf("El numero de bits no puede ser negativo\n");
        return 1;
    }
    
    switch (puerto) {
        
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