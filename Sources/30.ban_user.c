
#include "../Headers/30.ban_user.h"

void ban_user(Network *net, char* name){
    int i = searchNetwork (name, net, NAME);

    if (i == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return;
    }
    // Tant el post com el banned_user son una llista de string
    net->banned_user = expandPosts(net->banned_user, net->banned_users_size);
    net->banned_user[net->banned_users_size] = name;
    printf("\n%s has been banned from the Social Network!\n", name);
    net->banned_users_size++;
}

int search_banned_user(Network *net, char* name) {
    for (int i = 0; i<net->banned_users_size; i++) {
        if (strcmp(net->banned_user[i], name) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}


