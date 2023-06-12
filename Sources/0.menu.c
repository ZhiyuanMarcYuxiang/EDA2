//
// Created by Marc Bosch Manzano on 26/4/2023.
//

#include "../Headers/0.menu.h"

void showMenu () {

    printf("\nWelcome to ZHIYUMARC Network!\n");
    printf("What do you want to do?\n");

    Network *net = initNetwork ();

    readUsersFile(net, USERS_FILE);

    int option = INVALID_OPTION;

    while (option != OPTION_QUIT){

        printf("\n===== PRINCIPAL MENU =====\n\n");

        printf("%d. Insert new user.\n",OPTION_NEW_USER);
        printf("%d. List all existing users.\n",OPTION_LIST_USERS);
        printf("%d. Operate over an specific user.\n",OPTION_OPERATE_USER);
        printf("%d. Quit.\n",OPTION_QUIT);
        option = readInt("  Choose your option:\n");

        system("cls");

        // Afegim un nou usuari.
        if (option==OPTION_NEW_USER){
            newUser(net);
        }
        // Imprimim tots els usuaris.
        else if (option==OPTION_LIST_USERS){
            listUsers(*net);
        }
        // Inspeccionem la llista i mirem si hi ha l'usuari que busquem.
        else if (option==OPTION_OPERATE_USER){
            operateUserMenu (net);
        }

        else if (option==OPTION_QUIT)
            ; //DO NOTHING

        else
            printf("\nInvalid option!\n");
    }
    clearNetwork (net);
}
