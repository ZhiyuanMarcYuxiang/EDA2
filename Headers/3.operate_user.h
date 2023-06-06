//
// Created by Usuari on 27/5/2023.
//

#ifndef XARXA_SOCIAL_OPERATE_USER_H
#define XARXA_SOCIAL_OPERATE_USER_H

#include "30.ceo_utils.h"
#include "dictionary_utils.h"



#define OPTION_SEND_REQUEST (1)
#define OPTION_MANAGE_REQUESTS (2)
#define OPTION_NEW_POST (3)
#define OPTION_LIST_POSTS (4)


// c) Submenú per a operar amb un usuari
//      1) Enviar sol·liticituds d'amistat
//      2) Gestionar sol·licituds
//      3) Nova publicació
//      4) Llista de publicacions
//      5) Tornar al menú principal
void operateUserMenu (Network *net);

#endif //XARXA_SOCIAL_OPERATE_USER_H