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

void printSpaces (char previous_string[], int max_length){
    int spaces = max_length - strlen(previous_string);
    for (int j = 0; j < spaces; ++j) {
        printf(" ");
    }
}

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


int * array_maxAttributesLength (Network* net, int max_attributes_lengths[], char titles[][MAX_LENGTH]){

    for (int i = 0; i < ATTRIBUTES; ++i) {
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


void printTitles (char titles[][MAX_LENGTH], int *max_attributes_lengths){
    // Imprimim els títols.
    for(int i=0; i<TITLES; i++){
        printf("%s ",titles[i]);
        printSpaces (titles[i], max_attributes_lengths[i]);
    }
    printf("\n");
}


void printUser (User user, int *max_attributes_lengths){

    for (int i = 0; i < ATTRIBUTES; ++i) {
        if (i<HOBBY1) {
            printf("%s ",user.data[i]);
            printSpaces (user.data[i], max_attributes_lengths[i]);
        }
        else if (i<=HOBBY4){
            printf("%s; ",user.data[i]);
        }
        else
            printf("%s\n",user.data[i]);
    }
}


void listUsers (Network net){

    printf("\nRegistered users: %d\n\n",net.size_users);

    char titles[TITLES][MAX_LENGTH];
    createArrayTitles(titles);

    int max_attributes_lengths[ATTRIBUTES];
    array_maxAttributesLength(&net, max_attributes_lengths, titles);

    printTitles(titles, max_attributes_lengths);

    for(int i=0; i<net.size_users; i++)
        printUser (net.user[i], max_attributes_lengths);

}