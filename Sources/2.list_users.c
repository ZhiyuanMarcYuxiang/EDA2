//
// Created by Usuari on 13/5/2023.
//

#include "../Headers/2.list_users.h"

void createArrayTitles (char titles[TITLES][MAX_LENGTH]){
    strcpy(titles[NAME],"NAME");
    strcpy(titles[AGE],"AGE");
    strcpy(titles[EMAIL],"E-MAIL");
    strcpy(titles[CITY],"CITY");
    strcpy(titles[HOBBY1],"HOBBIES");
}

// De cada columna d'atributs de dades, mirem quina és l'string que té longitud màxima i retornem aquest valor.
int maxAttributesLengths(User *user,int size, int type){
    int max = 0;
    int length;
    for (int i = 0; i < size; ++i) {
        length = strlen(user[i].data[type]);
        if(max < length)
            max = length;
    }
    return max;
}

int *array_maxAttributesLength (Network* net, int max_attributes_lengths[], char titles[][MAX_LENGTH]){

    for (int i = 0; i < SIZE_DATA; ++i) {
        max_attributes_lengths[i] = maxAttributesLengths (net->user, net->size_users, i);
        if (i<TITLES){
            int length = strlen(titles[i]);
            if (length > max_attributes_lengths[i] ){
                max_attributes_lengths[i] = length;
            }
        }
    }
    return max_attributes_lengths;
}

// Imprimim els títols.
void printTitles (char titles[][MAX_LENGTH], int *max_attributes_lengths){

    for(int i=0; i<TITLES; i++){
        printf("%s ",titles[i]);
        printSpaces (titles[i], max_attributes_lengths[i]);
    }
    printf("\n");
}


void printUser (User user, int *max_attributes_lengths){

    // Iterem per cada columna.
    for (int i = 0; i < SIZE_DATA; ++i) {

        // Per a NAME, AGE, EMAIL I CITY, imiprimim l'atribut i omplim amb espais proporcionals.
        if (i<HOBBY1) {
            printf("%s ",user.data[i]);
            printSpaces (user.data[i], max_attributes_lengths[i]);
        }

        // Per als 4 primers hobbies, els imprimim separant-los amb punt i coma.
        else if (i<=HOBBY4){
            printf("%s; ",user.data[i]);
        }

        // Per a l'últim hobby, l'imprimim amb un caràcter de salt de línia.
        else
            printf("%s\n",user.data[i]);
    }
}


void listUsers (Network net){

    printf("\nRegistered users: %d\n\n",net.size_users);

    // Creem una llista amb els títols dels atributs dels usuaris.
    char titles[TITLES][MAX_LENGTH];

    // Creem una llista amb les màximes longituds de les strings dels atributs.
    createArrayTitles(titles);

    int max_attributes_lengths[SIZE_DATA];
    array_maxAttributesLength(&net, max_attributes_lengths, titles);

    // Imprimim els títols i després usuari a usuari.
    printTitles(titles, max_attributes_lengths);

    for(int i=0; i<net.size_users; i++)
        printUser (net.user[i], max_attributes_lengths);
}