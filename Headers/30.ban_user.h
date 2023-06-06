//
// Created by yjian on 05/06/2023.
//

#ifndef XARXA_SOCIAL_30_BAN_USER_H
#define XARXA_SOCIAL_30_BAN_USER_H

#include "31.send_request.h"

void ban_user(Network *net, char* name);

int search_banned_user(Network *net, char* name);

#endif //XARXA_SOCIAL_30_BAN_USER_H
