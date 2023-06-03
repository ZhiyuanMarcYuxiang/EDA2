//
// Created by Usuari on 27/5/2023.
//

#ifndef XARXA_SOCIAL_OPERATE_USER_H
#define XARXA_SOCIAL_OPERATE_USER_H

#define OPTION_SEARCH_MOST_USED (1)
#define OPTION_SEND_REQUEST (1)
#define OPTION_MANAGE_REQUESTS (2)
#define OPTION_NEW_POST (3)
#define OPTION_LIST_POSTS (4)
#define OPTION_RETURN_MENU (0)

#include "31.send_request.h"

// c) Submenú per a operar amb un usuari
//      1) Enviar sol·liticituds d'amistat
//      2) Gestionar sol·licituds
//      3) Nova publicació
//      4) Llista de publicacions
//      5) Tornar al menú principal
void operateUserMenu (Network *net);

#endif //XARXA_SOCIAL_OPERATE_USER_H