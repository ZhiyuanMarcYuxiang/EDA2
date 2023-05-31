//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/34.list_posts.h"

// Bàsicament, ens hem de dedicar a imprimir els posts d'un usuari per pantalla.
// Més o menys, ha de tenir aquesta forma la funció, però es pot ampliar més perquè quedi millor
// la impressió per pantalla dels posts.

void listPosts (User *user){
    for (int i = 0; i<user->size_posts; i++){
        printf("%d. %s\n", i, user->post[i]);
    }
}