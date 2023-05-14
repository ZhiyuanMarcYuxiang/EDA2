//
// Created by Usuari on 26/4/2023.
//


#ifndef XARXA_SOCIAL_UTILS_H
#define XARXA_SOCIAL_UTILS_H


#define TRUE (1)
#define FALSE (0)

#include "stdio.h"
#include "string.h"
#include "stdlib.h"


// Funcions per a llegir enters i validar-los.
int read_int(const char *message);
void flush_input();

// Funció per a llegir una cadena d'una longitud concreta.
void read_bounded_str(char string[], const char type[], int max);





#endif //XARXA_SOCIAL_UTILS_H
