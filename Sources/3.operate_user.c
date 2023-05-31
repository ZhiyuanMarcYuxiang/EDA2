//
// Created by Usuari on 27/5/2023.
//

#include "../Headers/3.operate_user.h"


User* chooseUser (Network *net){
    printf("\nWhich user do you want to operate with?\n");

    char * attribute = readString();

    int idx = searchNetwork (attribute, net, NAME);

    if(idx == USER_NOT_FOUND)
        return NULL;
    else
        return &net->user[idx];
}


void operateUserMenu (Network *net) {

    User* choosed_user = chooseUser (net);

    if (choosed_user == NULL){
        printf("\nThe user was not found!\n");
        return;
    }

    printf("\nProfile of user %s initialized!\n",choosed_user->data[NAME]);

    int option = INVALID_OPTION;

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
            newPost (choosed_user);
        }
        else if(option == OPTION_LIST_POSTS){
            listPosts (choosed_user->post,choosed_user->size_posts);
        }

        else if(option == OPTION_RETURN_MENU){
            ;//DO NOTHING
        }
        else{
            printf("\nInvalid option!\n");
        }
    }
}
