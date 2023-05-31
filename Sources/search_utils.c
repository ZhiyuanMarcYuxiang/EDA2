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
    int size = net->size;

    if (size > NULL_SIZE){
        if(fencedAttribute (attribute, user, size, type) == TRUE){
            return binarySearch (attribute, user, size, type);
        }
    }
    return USER_NOT_FOUND;
}