//
// Created by Usuari on 27/5/2023.
//

#include "../Headers/3.operate_user.h"

void selectiveSort (Dict* dictionary) {
    Element temp;
    for(int j = 0; j<10; j++) {
        int idx_max = j;
        for (int i = j+1; i<dictionary->count; i++) {
            if (dictionary->elements[i].value> dictionary->elements[idx_max].value) {
                idx_max = i;
            }
        }
        if(idx_max != j) {
            temp = dictionary->elements[j];
            dictionary->elements[j] = dictionary->elements[idx_max];
            dictionary->elements[idx_max] = temp;
        }
    }
    return;
}

void operateUserMenu (Network *net) {
    int option = INVALID_OPTION;
    printf("\nWhich user do you want to operate with?\n");
    char *name = readString();
    if (strcmp(name, "CEO") == 0) {
        while(option != OPTION_RETURN_MENU) {
            printf("%d. Search most frequent words used.\n", OPTION_SEARCH_MOST_USED);
            option = readInt("Choose your option:\n");
            if (option == OPTION_SEARCH_MOST_USED) {
                net->dictionary->elements[0].value = 0;
                selectiveSort(net->dictionary);
                print_dictionary_elements(net->dictionary);
            }
            else if(option == OPTION_RETURN_MENU){
                ;//DO NOTHING
            }
            else {
                printf("\nInvalid option\n");
            }
        }
    }
    int i = searchNetwork (name, net, NAME);

    if (i == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
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
