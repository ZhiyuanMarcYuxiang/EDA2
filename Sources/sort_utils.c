//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/sort_utils.h"


/**
 * @param n: Llista d'usuaris inicialitzada.
 * Si la llista té més d'un usuari, aleshores ordenem la llista. En cas contrari, no caldrà fer-ho.
 */

void sortNetwork (Network *net, int type){

    if(net->size > 1)                                               // Ordena si hi ha més d'un usuari.
        if(type != net->order)                                      // Ordena si el tipus d'atribut que volem ordenar no està ordenat.
            net->user = mergeSort (net->user, net->size, type);     // Apliquem l'ordenació combinada.
    net->order = type;                                              // Actualitzem l'estat d'ordenació de la llista: la llista ja està ordenada segons aquest atribut.
}


/**
 * @param user: Usuari inicialitzat amb valors per als seus atributs.
 * @param size: Mida de la llista d'usuaris.
 * @param type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).
 * @return Retornem una nova llista d'usuaris ordenada ascendentment a partir de l'atribut del nom.
 * "Merge Sort" és un ordenament de recursiu a partir de trossejar i combinar la llista.
 */
User* mergeSort(User *user, int size, int type){
    //printf("%s\n", user[0].attr[type]);

    if (size == 1)
        return user;

    int mid = size/2;

    User *lowerHalf = &user[0];
    User *upperHalf = &user[mid];

    lowerHalf = mergeSort(lowerHalf, mid, type);
    upperHalf = mergeSort(upperHalf, size - mid, type);

    return merge(lowerHalf, mid, upperHalf, size-mid, type);
}


/**
 * @param userA: Sub-llista d'usuaris inicialitzada (meitat inferior).
 * @param sizeA: Mida de "userA".
 * @param userB: Sub-llista d'usuaris inicialitzada (meitat superior)
 * @param sizeB: Mida de "userB".
 * @param type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).
 * @return Retornem una nova llista d'usuaris, userC, que és la combinació ordenada de les llistes userA i userB.
 */
User* merge(User *userA, int sizeA, User *userB, int sizeB, int type){

    User *userC = malloc(sizeof(User));            // Reservem memòria per a una nova llista d'usuaris anomenada "C".
    int a=0, b=0, c=0;

    while(a!=sizeA && b!=sizeB){                   // Afegim els elements de la llista "A" i la "B" de forma ordenada a la "C".

        userC = expandUsers(userC, c + 1);

        if (compAttribute (userA[a],userB[b],type) == LESSTHAN){  // Si l'atribut d'un usuari de "A" és més petit que "B", el copiem a "C".
            copyUser (&userC[c], &userA[a]);
            a++;
        }
        else{
            copyUser (&userC[c], &userB[b]);
            b++;
        }
        c++;
    }

    // En aquest punt, alguna de les dues llistes, "A" o "B", està buida.

    while(a != sizeA){                            // Afegim els elements que falten de "A" a la llista "C".
        userC = expandUsers(userC, c + 1);
        copyUser (&userC[c], &userA[a]);
        a++; c++;
    }

    while (b != sizeB) {                         // Afegim els elements que falten de "B" a la llista "C".
        userC = expandUsers(userC, c + 1);
        copyUser (&userC[c], &userB[b]);
        b++; c++;
    }
    return userC;                            // Retornem la llista combinada.
}



int compAttribute (User userA, User userB, int type){
    return strcmp(userA.attr[type], userB.attr[type]);
}


/**
 * @param copy: Usuari no necessàriament inicialitzat que rebrà atributs copiats.
 * @param origin: Usuari inicialitzat d'on s'extrauran els valors per a copiar-los.
 * Copiem tots els valors de l'usuari d'origen a l'usuari còpia.
 */
void copyUser (User *copy,User *origin){

    for (int i = 0; i < ATTRIBUTES; ++i) {
        copy->attr[i] = init_and_copy(origin->attr[i]);
    }
}


