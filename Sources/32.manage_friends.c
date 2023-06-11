//
// Created by Usuari on 28/5/2023.
//

#include "../Headers/32.manage_friends.h"

// Bàsicament, ens hem de dedicar a imprimir els posts d'un usuari per pantalla.
// Més o menys, ha de tenir aquesta forma la funció, però es pot ampliar més perquè quedi millor
// la impressió per pantalla dels posts.

void listFriendPosts (Network* net, char **friend, int size_friends) {

    printf("\nSearch for which friend's post?\n");
    char *friend_name = readString();

    if (searchInStringArray (friend_name, friend, size_friends) == STRING_NOT_FOUND){
        printf("\nThe friend user was not found!\n");
        return;
    }
    int idx_friend = searchNetwork(friend_name, net, NAME);

    char ** post = net->user[idx_friend].post;
    int size_posts = net->user[idx_friend].size_posts;

    listStringArray (post, size_posts, friend_name, "post");
}


void removeFriend (Network* net, int idx_operating_user, char **friend, int size_friends){

    if(size_friends == NULL_SIZE){
        printf("You don't have any post!\n");
        return;
    }

    printf("\nWhich friend do you want to remove?\n");
    char *friend_name = readString();

    int idx_friend = searchInStringArray (friend_name, friend, size_friends);

    if (idx_friend == STRING_NOT_FOUND){
        printf("\nThe friend user was not found!\n");
        return;
    }

    // Ens esborra un amic.
    deleteString_InArray(friend, size_friends, idx_friend);
    net->user[idx_operating_user].size_friends += DECREMENT_SIZE;

    printf("%s has been removed from your friend list!\n", friend_name);
}


void manageFriendsMenu (Network *net, int idx_operating_user) {

    int option = INVALID_OPTION;

    while(option != OPTION_RETURN_TO_OPERATE_USER_MENU){

        printf("\nMANAGE FRIEANDS MENU\n\n");

        printf("%d. See my friend list.\n", OPTION_LIST_FRIENDS);
        printf("%d. See friend's posts.\n", OPTION_FRIEND_POST);
        printf("%d. Remove friend.\n", OPTION_REMOVE_FRIEND);

        printf("%d. Return to previous menu.\n",OPTION_RETURN_TO_OPERATE_USER_MENU);
        option = readInt("Choose your option:\n");

        //system("cls");

        char ** friend = net->user[idx_operating_user].friend;
        int size_friends = net->user[idx_operating_user].size_friends;

        if(option == OPTION_LIST_FRIENDS){
            listStringArray (friend, size_friends, "You", "friend");
        }
        else if(option == OPTION_FRIEND_POST){
            listFriendPosts(net, friend, size_friends);
        }

        else if(option == OPTION_REMOVE_FRIEND){
            removeFriend (net, idx_operating_user, friend, size_friends);
        }

        else if(option == OPTION_RETURN_TO_OPERATE_USER_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }

    }
}