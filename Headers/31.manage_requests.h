//
// Created by Usuari on 28/5/2023.
//

#ifndef XARXA_SOCIAL_31_MANAGE_REQUESTS_H
#define XARXA_SOCIAL_31_MANAGE_REQUESTS_H

#include "32.manage_friends.h"

#define OPTION_SEND_TO_CHOOSED_USER (1)
#define OPTION_SEND_TO_RANDOM_USER (2)
#define OPTION_ACCEPT_DENY_REQUESTS (3)

void manageRequestsMenu (Network *net, int idx_operating_user);

// Imprimeixes els amics
// Imprimeixes els nous amics
// Imprimeixes les sol·licituds que t'han enviat
// Triar si acceptar-les o no
// Si acceptes, borres la sol·licitud i l'afegeixes un amic. També l'amic t'afegeix a tu com a nou amic (imprimir).
// Si no, borres la sol·licitud també, però no fas res.

#endif //XARXA_SOCIAL_31_MANAGE_REQUESTS_H
