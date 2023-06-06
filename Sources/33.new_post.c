//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/33.new_post.h"

void newPost (Network *net, int idx) {
    int last = net->user[idx].posts_size;
    net->user->post = expandStringArray(net->user->post, last);
    printf("\nWrite your new post:\n");
    net->user[idx].post[last] = readString();
    read_words(net->dictionary, net->user[idx].post[last]);
    net->user[idx].posts_size += INCREMENT_SIZE;
}
