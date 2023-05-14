//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/data_structures.h"



/**
 * @return Inicialitza una llista dinàmica d'usuaris.
 */
Network* initNetwork(){
    Network *n = malloc(sizeof(Network));
    n->size = NULL_SIZE;
    n->order = NOT_ORDERED;
    n->user = malloc(sizeof(User));
    return n;
}


/**
 * @param net: Xarxa social inicialitzada.
 * Funció que allibera les al·locacions manuals de memòria de l'estructura de la xarxa.
 */
void clearNetwork (Network *net){
    // Elimino cadascuna de les arrays d'atributs.
    free(net->user);
    free(net);
}

/**
 * @param user: Usuari declarat dinàmicament.
 * @param real_size: Mida actual de llista d'usuaris.
 * @return Ampliem els espais de memòria de l'usuari segons un factor multiplicador respecte la mida de la llista.
 * Ex: Tenint MULT_FACTOR = 5, Si tenim 1 usuari, ampliem amb 6 nou usuaris. Si la mida és 6, 6-1 mòdul 5 és 0 i
 * ampliem amb 11 usuaris.
 */
User * expandUsers (User *user, int real_size){
    if ((real_size-1) % MULT_FACTOR == 0) {
        int new_size = real_size + MULT_FACTOR;
        user = realloc(user, new_size * sizeof(User));
    }
    return user;
}

/**
 *
 * @param origin: String que serà copiada.
 * @return Reservem memòria per una nova string -atribut de l'usuari- i hi copiem el contingut d'una string.
 * Retornem el punter d'aquesta string nova.
 */
char* init_and_copy (char origin[]){
    int length = strlen(origin);
    char* copy = initAttribute(length);
    strcpy(copy, origin);
    return copy;
}

char* initAttribute (int size){
    char* attribute = malloc(size * sizeof(char));
    return attribute;
}