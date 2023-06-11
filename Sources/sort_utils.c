//
// Created by Usuari on 26/4/2023.
//

#include "../Headers/sort_utils.h"

/// Funcions de comparació de dades

int compAttribute (User userA, User userB, int type){
    return strcmp(userA.data[type], userB.data[type]);
}

/// Combinació de dues subllistes d'usuaris.

User* merge(User *userA, int sizeA, User *userB, int sizeB, int type){

    User *userC = initUser();
    int a = SET_ZERO, b = SET_ZERO, c = SET_ZERO ;

    while(a!=sizeA && b!=sizeB){

        userC = expandUsers(userC, c);

        if (compAttribute (userA[a],userB[b],type) == LESSTHAN){
            copyUser (&userC[c], &userA[a]); a++;
        }
        else{
            copyUser (&userC[c], &userB[b]); b++;
        }
        c++;
    }

    while(a != sizeA){
        userC = expandUsers(userC, c);
        copyUser (&userC[c], &userA[a]);
        a++; c++;
    }

    while (b != sizeB) {
        userC = expandUsers(userC, c);
        copyUser (&userC[c], &userB[b]);
        b++; c++;
    }

    return userC;
}


User* mergeSort(User *user, int size, int type){

    if (size == ONE_SIZE)
        return user;

    int mid = size/2;

    User *lowerHalf = &user[0];
    User *upperHalf = &user[mid];

    lowerHalf = mergeSort(lowerHalf, mid, type);
    upperHalf = mergeSort(upperHalf, size - mid, type);

    return merge(lowerHalf, mid, upperHalf, size-mid, type);
}


void sortNetwork (Network *net, int type){

    if(net->size_users > ONE_SIZE)
        if(type != net->order_users)
            net->user = mergeSort (net->user, net->size_users, type);
    net->order_users = type;
}

void selectiveSort (Dict* dictionary) {

    Element temp;
    for(int j = 0; j<10; j++) {
        int idx_max = j;
        for (int i = j+1; i<dictionary->current_elements; i++) {
            if (dictionary->element[i].value > dictionary->element[idx_max].value) {
                idx_max = i;
            }
        }
        if(idx_max != j) {
            temp = dictionary->element[j];
            dictionary->element[j] = dictionary->element[idx_max];
            dictionary->element[idx_max] = temp;
        }
    }
}