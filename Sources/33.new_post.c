//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/33.new_post.h"

// Es pot pensar de forma molt semblant a New Users.

void newPost (User *user) {
    int last = user->size_posts;

    user->post = expandPosts(user->post, last);

    printf("Write your new post:\n");
    user->post[last] = readString();

    user->size_posts += INCREMENT_SIZE;
}
