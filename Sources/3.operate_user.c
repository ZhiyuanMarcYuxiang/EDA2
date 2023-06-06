//
// Created by Usuari on 27/5/2023.
//

#include "../Headers/3.operate_user.h"

void operateUserMenu (Network *net) {
    int option = INVALID_OPTION;
    printf("\nWhich user do you want to operate with?\n");
    char *name = readString();
    if (strcmp(name, "CEO") == 0) {
        while(TRUE) {
            printf("\n%d. Search 10 most used words.\n", OPTION_MOST_USED_WORDS);
            printf("%d. Ban user.\n", OPTION_BAN_USER);
            printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);
            option = readInt("Choose your option:\n");
            if (option == OPTION_MOST_USED_WORDS) {
                net->dictionary->elements[0].value = 0;
                selectiveSort(net->dictionary);
                print_dictionary_elements(net->dictionary);
            }
            else if(option == OPTION_BAN_USER) {
                printf("\nWhich user do you want to ban?\n");
                name = readString();
                ban_user(net, name);
            }
            else if(option == OPTION_RETURN_MENU){
                return; //DO NOTHING
            }
            else {
                printf("\nInvalid option!\n");
            }
        }
    }
    int i = searchNetwork (name, net, NAME);

    if (i == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return;
    }
    if (search_banned_user(net, net->user[i].data[NAME]) == TRUE) {
        printf("\nYour account has been disabled for violating our terms.\n");
        printf("Learn how you may be able to restore your account entering:\n");
        printf("https://www.youtube.com/watch?v=dQw4w9WgXcQ\n");
        return;
    }
    printf("\nProfile of user %s initialized!\n",net->user[i].data[NAME]);

    while(option != OPTION_RETURN_MENU){

        printf("\n%d. Send friend request.\n", OPTION_SEND_REQUEST);
        printf("%d. Manage the pending requests.\n", OPTION_MANAGE_REQUESTS);
        printf("%d. Make a new post.\n", OPTION_NEW_POST);
        printf("%d. List all of the user posts.\n", OPTION_LIST_POSTS);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);
        option = readInt("Choose your option:\n");

        if(option == OPTION_SEND_REQUEST){
            sendRequest (net);
        }
        else if(option == OPTION_MANAGE_REQUESTS){
            manageRequests (net);
        }
        else if(option == OPTION_NEW_POST){
            newPost (net, i);
        }
        else if(option == OPTION_LIST_POSTS){
            listPosts (&net->user[i]);
        }

        else if(option == OPTION_RETURN_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }
    }
}
