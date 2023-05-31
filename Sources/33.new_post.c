//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/33.new_post.h"

// Funció molt similar a newUser.

void newPost (User *user) {
    int last = user->posts_size;

    user->post = expandPosts(user->post, last);

    printf("\nWrite your new post:\n");
    user->post[last] = readString();

    user->posts_size += INCREMENT_SIZE;
}
