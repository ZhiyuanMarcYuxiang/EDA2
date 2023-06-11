//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/34.list_posts.h"

// Bàsicament, ens hem de dedicar a imprimir els posts d'un usuari per pantalla.
// Més o menys, ha de tenir aquesta forma la funció, però es pot ampliar més perquè quedi millor
// la impressió per pantalla dels posts.

void listPosts (User *user, int who) {

    char **post = user->post;
    int size_posts = user->size_posts;

    // La variable who s'utilitza per saber si els post son de l'usuari que hem inicialitzat
    // o dels seus amics.

    if (size_posts == NULL_SIZE && who != FRIEND){
        printf("\nYou don't have any post.\n");
        return;
    }
    else if(size_posts == NULL_SIZE) {
        printf("\n%s doesn't have any post.\n", user->data[NAME]);
        return;
    }

    if (who != FRIEND) {
        printf("\nYou have %d post.\n", size_posts);
    }
    else{
        printf("\n%s has %d post.\n", user->data[NAME], size_posts);
    }
    if(size_posts > ONE_SIZE){
        printf("\nWe will list all the posts from newest to oldest.\n\n");
    }

    for (int i = 0; i < size_posts; i++)
        printf("%d. %s\n", i+1, post[(size_posts-1)-i]);
}

void listfriendPosts (Network* net, User *operating_user) {
    printf("\nSearch for which friend's post?\n");
    char *name = readString();

    int friend_idx = searchInStringArray (operating_user->friend, operating_user->size_friends, name);

    if (friend_idx == STRING_NOT_FOUND){
        printf("\nThe friend user was not found!\n");
        return;
    }
    int idx = searchNetwork(name, net, NAME);

    listPosts(&net->user[idx], FRIEND);
}

void listFriends(User* operating_user) {
    if (operating_user->size_friends == 0) {
        printf("\nYou don't have any friend!\n");
        return;
    }
    for (int i = 0; i<operating_user->size_friends; i++) {
        printf("Friend: %s\n", operating_user->friend[i]);
    }
}