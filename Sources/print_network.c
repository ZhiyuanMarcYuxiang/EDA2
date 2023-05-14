//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/print_network.h"

/**
 * @param net: Llista d'usuaris inicialitzada.
 * Imprimeix per pantalla tots els usuaris inscrits a la xarxa.
 */
void printNetwork (Network *net){

    printf("\nRegistered users: %d\n\n",net->size);       // Imrimim la quantitat d'usuaris.

    char ** titles = array_titles();                       // Creem una llista amb els títols dels atributs dels usuaris.
    int * maximums = array_maxAttributes (net,titles);     // Creem una llista amb les màximes longituds de les strings dels atributs.

    for(int i=0; i<TITLES; i++){                          // Imprimim els títols.
        printf("%s ",titles[i]);
        printSpaces (maximums[i],titles[i]);
    }
    printf("\n");

    for(int i=0; i<net->size; i++)                        // Imprimim usuari a usuari.
        printUser (net->user[i], maximums);
}

/**
 * @param user: Usuari inicialitzat amb valors.
 * @param maximums: Llista que conté les longituds de les strings més llargues de cada columna d'atributs.
 * Imprimim per pantalla els atributs d'un usuari.
 */
void printUser (User user, int *maximums){

    for (int i = 0; i < ATTRIBUTES; ++i) {         // Iterem per cada columna.
        if (i<HOBBY1) {                            // Per a NAME, AGE, EMAIL I CITY.
            printf("%s ",user.attr[i]);             // Imiprimim l'atribut i omplim amb espais proporcionals.
            printSpaces (maximums[i],user.attr[i]);
        }
        else if (i<=HOBBY4){                       // Per als 4 primers hobbies.
            printf("%s; ",user.attr[i]);            // Els imprimim separant-los amb punt i coma.
        }
        else                                       // Per a l'últim hobby.
            printf("%s\n",user.attr[i]);            // L'imprimim amb un caràcter de salt de línia.
    }
}


char** array_titles (){
    char ** titles = malloc(TITLES * sizeof(char *));
    for (int i = 0; i < TITLES; ++i) {
        titles[i] = malloc(10 * sizeof(char));
    }
    strcpy(titles[NAME],"NAME");
    strcpy(titles[AGE],"AGE");
    strcpy(titles[EMAIL],"E-MAIL");
    strcpy(titles[CITY],"CITY");
    strcpy(titles[HOBBIES],"HOBBIES");
    return titles;
}


void printSpaces (int maximum, char *title){
    int spaces = maximum - strlen(title);
    for (int j = 0; j < spaces; ++j) {
        printf(" ");
    }
}


int * array_maxAttributes(Network* net, char** titles){
    int* maximums = malloc(ATTRIBUTES * sizeof(char));
    for (int i = 0; i < ATTRIBUTES; ++i) {
        maximums[i] = maxAttributes (net->user,net->size,i);
        if (i<TITLES){
            int length = strlen(titles[i]);
            if (length > maximums[i] ){
                maximums[i] = length;
            }
        }
    }
    return maximums;
}

/**
 * @param user: Llista d'usuaris inicialitzada.
 * @param size: Mida de la llista d'usuaris.
 * @param type: Tipus d'atribut de l'usuari (NAME, AGE, EMAIL, etc.).
 * @return De cada columna d'atributs, mirem quina és l'string que té longitud màxima i retornem aquest valor.
 */
int maxAttributes(User *user,int size, int type){
    int max = 0;
    int length;
    for (int i = 0; i < size; ++i) {
        length = strlen(user[i].attr[type]);
        if(max < length)
            max = length;
    }
    return max;
}