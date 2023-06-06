//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/34.list_posts.h"

// Bàsicament, ens hem de dedicar a imprimir els posts d'un usuari per pantalla.
// Més o menys, ha de tenir aquesta forma la funció, però es pot ampliar més perquè quedi millor
// la impressió per pantalla dels posts.

void listPosts (User *user) {

    char **post = user->post;
    int size_posts = user->size_posts;

    if (size_posts == NULL_SIZE){
        printf("\nYou don't have any post.\n");
    return;
    }

    printf("\nYou have %d post.\n", size_posts);

    if(size_posts > ONE_SIZE){
        printf("\nWe will list all the posts from newest to oldest.\n\n");
    }

    for (int i = 0; i < size_posts; i++)
        printf("%d. %s\n", i+1, post[(size_posts-1)-i]);
}