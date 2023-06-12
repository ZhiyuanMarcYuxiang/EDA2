#include "../Headers/30.ceo_utils.h"

void unbanUser(Network *net){

    // Triem l'usuari a desbanejar pel seu nom. Mirem que existeixi a la llista.

    printf("\nWhich user do you want to unban?\n");
    char *name = readString();

    int banned_idx = searchInStringArray (name, net->banned_user, net->size_banned_users);

    if (banned_idx == STRING_NOT_FOUND){
        printf("\nThis user is not banned!\n");
        return;
    }

    int size = net->size_banned_users;

    // En cas de trobar l'usuari banejat, ens el borra de la llista dels banejats.
    deleteString_InArray(net->banned_user, banned_idx, size);

    net->size_banned_users += DECREMENT_SIZE;

    printf("Now, this user is not banned from ZhiYuMarc Network.\n");
}

void banUser(Network *net){

    // Triem l'usuari a banejar pel seu nom. Mirem que existeixi a la llista.
    printf("\nWhich user do you want to ban?\n");
    char *name = readString();

    if (searchNetwork (name, net, NAME) == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return;
    }

    int last = net->size_banned_users;

    // Expandim la llista d'strings dels usuaris banejats.
    net->banned_user = expandStringArray(net->banned_user, last);

    // Afegim aquest nou usuari banejat a l'última posició. Només ens cal anotar el seu nom.

    net->banned_user[last] = name;

    net->size_banned_users += INCREMENT_SIZE;

    printf("\n%s has been banned from the Social Network!\n", name);
}

#define SEE_TERMS_OF_USE 1

void printIsBannedMessage(){
    printf("\nYour account has been disabled for violating our terms.\n");
    printf("Learn how you may be able to restore your account entering\n");
    printf("in our Social Network Terms of Use.\n");

    int option = readInt("If you want to see our Terms of Use, click 1.\n");

    if (option != SEE_TERMS_OF_USE)
        return;

    // Imprimeix el fitxer amb les condicions de la xarxa.
    FILE *fp = fopen ("../Files/Social_Network_Terms.txt",READING_MODE);

    printf("%d",fp == NULL);
    char c;
    do{
        c = fgetc(fp);
        printf("%c",c);
    } while (c != EOF);

    printf("\n");
    fclose(fp);
}

void listBannedUsers(char** banned_user, int size){
    for (int i = 0; i < size; i++)
        printf("%d. %s\n", i+1, banned_user[i]);
}

void ceoMenu (Network *net){

    int option = INVALID_OPTION;

    while(option != OPTION_RETURN_MENU) {

        printf("\n===== DEVELOPER MENU =====\n\n");

        printf("%d. Search 10 most used words.\n", OPTION_MOST_USED_WORDS);
        printf("%d. Ban user.\n", OPTION_BAN_USER);
        printf("%d. Unban user.\n",OPTION_UNBAN_USER);
        printf("%d. List banned users.\n",OPTION_LIST_BANNED);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);

        option = readInt("Choose your option:\n");

        system("cls");

        if (option == OPTION_MOST_USED_WORDS) {
            net->dictionary->element[0].value = 0;
            selectiveSort(net->dictionary);
            print_dictionary_elements(net->dictionary);
        }
        else if(option == OPTION_BAN_USER) {
            banUser(net);
        }
        else if(option == OPTION_UNBAN_USER) {
            unbanUser(net);
        }
        else if(option == OPTION_LIST_BANNED){
            listBannedUsers(net->banned_user,net->size_banned_users);
        }
        else if(option == OPTION_RETURN_MENU){
            // Go to principal menu.
        }
        else {
            printf("\nInvalid option!\n");
        }
    }
}


