//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/34.list_posts.h"

// Bàsicament, ens hem de dedicar a imprimir els posts d'un usuari per pantalla.
// Més o menys, ha de tenir aquesta forma la funció, però es pot ampliar més perquè quedi millor
// la impressió per pantalla dels posts.

void listPosts (char **posts, int size_posts){

    printf("You have %d posts", size_posts);

    if(size_posts == 0) return;

    printf("We will list all the posts from newest to oldest");
        for (int i = size_posts; i>=0; i--)
            printf("%d. %s\n", i, posts[i]);
}