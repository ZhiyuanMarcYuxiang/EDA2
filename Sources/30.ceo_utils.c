#include "../Headers/30.ceo_utils.h"

void unbanUser(Network *net){

    // Triem l'usuari a desbanejar pel seu nom. Mirem que existeixi a la llista.

    printf("\nWhich user do you want to unban?\n");
    char *name = readString();

    int banned_idx = searchIfUserIsBanned (net, name);

    if (banned_idx == BANNED_NOT_FOUND){
        printf("\nThe banned user was not found!\n");
        return;
    }

    int size = net->banned_users_size;

    // En cas de trobar l'usuari banejat, ens el borra de la llista dels banejats.
    deleteString_InArray(net->banned_user, banned_idx, size);

    net->banned_users_size += (-INCREMENT_SIZE);
}

void banUser(Network *net){

    // Triem l'usuari a banejar pel seu nom. Mirem que existeixi a la llista.
    printf("\nWhich user do you want to ban?\n");
    char *name = readString();

    if (searchNetwork (name, net, NAME) == USER_NOT_FOUND){
        printf("\nThe user was not found!\n");
        return;
    }

    int last = net->banned_users_size;

    // Expandim la llista d'strings dels usuaris banejats.
    net->banned_user = expandStringArray(net->banned_user, last);

    // Afegim aquest nou usuari banejat a l'última posició. Només ens cal anotar el seu nom.

    net->banned_user[last] = name;

    printf("\n%s has been banned from the Social Network!\n", name);

    net->banned_users_size += INCREMENT_SIZE;
}

// Funció de cerca lineal. Suposem que la quanitat d'usuaris banejats no serà excessivament gran.

int searchIfUserIsBanned(Network *net, char* name) {

    for (int idx = 0; idx<net->banned_users_size; idx++)

        // Retornem l'índex d'aquell usuari banejat dins l'estructura dels banejats si el troba.
        if (strcmp(net->banned_user[idx], name) == 0)
            return idx;

    // Constant retornada de (-1) si no hem trobat l'usuari banejat.
    return BANNED_NOT_FOUND;
}

void printIsBannedMessage(){
    printf("\nYour account has been disabled for violating our terms.\n");
    printf("Learn how you may be able to restore your account entering\n");
    printf("in our file Network_Social_Terms.\n");
}

void listBannedUsers(char** banned_user, int size){
    for (int i = 0; i < size; i++)
        printf("%d. %s\n", i+1, banned_user[i]);
}

void ceoMenu (Network *net){

    int option = INVALID_OPTION;

    while(option != OPTION_RETURN_MENU) {

        printf("\n%d. Search 10 most used words.\n", OPTION_MOST_USED_WORDS);
        printf("%d. Ban user.\n", OPTION_BAN_USER);
        printf("%d. Unban user.\n",OPTION_UNBAN_USER);
        printf("%d. List banned users.\n",OPTION_LIST_BANNED);
        printf("%d. Return to principal menu.\n",OPTION_RETURN_MENU);

        option = readInt("Choose your option:\n");

        if (option == OPTION_MOST_USED_WORDS) {
            net->dictionary->elements[0].value = 0;
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
            listBannedUsers(net->banned_user,net->banned_users_size);
        }
        else if(option == OPTION_RETURN_MENU){
            // Go to principal menu.
        }
        else {
            printf("\nInvalid option!\n");
        }
    }
}


