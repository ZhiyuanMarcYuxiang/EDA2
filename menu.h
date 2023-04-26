//
// Created by Usuari on 26/4/2023.
//

// MARC BOSCH BRANCH

#ifndef XARXA_SOCIAL_MENU_H
#define XARXA_SOCIAL_MENU_H

#define INVALID_OPTION (-1)
#define OPTION_QUIT (0)
#define OPTION_NEW_USER (1)
#define OPTION_LIST_USERS (2)
#define OPTION_OPERATE_USER (3)

void show_menu();

void new_user();
void list_users();
void operate_user();

#endif //XARXA_SOCIAL_MENU_H
