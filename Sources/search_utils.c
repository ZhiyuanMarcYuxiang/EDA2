//
// Created by Usuari on 27/4/2023.
//

#include "../Headers/search_utils.h"

int binarySearch (char* attribute, User *user, int size, int type){

    int left,right,mid; int cmp;
    left = 0;
    right = size-1;

    while (left<=right) {

        mid = (left+right)/2;
        cmp = strcmp(attribute, user[mid].data[type]);

        if (cmp == GREATERTHAN)
            left = mid+1;
        else if (cmp == LESSTHAN)
            right = mid-1;
        else
            return mid;
    }
    return USER_NOT_FOUND;
}


int fencedAttribute (char* attribute, User* user, int size, int type){

    int first = 0;
    int last = size-1;

    int lowBound = strcmp(user[first].data[type], attribute);
    int highBound = strcmp(user[last].data[type], attribute);

    return LESSTHAN <= lowBound && highBound<= GREATERTHAN;
}


int searchNetwork (char* attribute, Network *net, int type){

    sortNetwork (net,type);

    User * user = net->user;
    int size = net->size_users;

    if (size > NULL_SIZE){
        if(fencedAttribute (attribute, user, size, type) == TRUE){
            return binarySearch (attribute, user, size, type);
        }
    }
    return USER_NOT_FOUND;
}

// Funció de cerca lineal. Suposem que la quanitat d'usuaris banejats no serà excessivament gran.

int searchInStringArray(char** StringArray, int size, char* String) {

    for (int idx = 0; idx<size; idx++)

        // Retornem l'índex d'aquell usuari banejat dins l'estructura dels banejats si el troba.
        if (strcmp(StringArray[idx], String) == 0)
            return idx;

    // Constant retornada de (-1) si no hem trobat l'usuari banejat.
    return STRING_NOT_FOUND;
}
