//
// Created by yjian on 05/06/2023.
//

#ifndef XARXA_SOCIAL_30_CEO_UTILS_H
#define XARXA_SOCIAL_30_CEO_UTILS_H

#include "31.send_request.h"

#define OPTION_MOST_USED_WORDS (1)
#define OPTION_BAN_USER (2)
#define OPTION_UNBAN_USER (3)
#define OPTION_LIST_BANNED (4)
#define OPTION_RETURN_MENU (0)



void printIsBannedMessage();

void ceoMenu (Network *net);

#endif //XARXA_SOCIAL_30_CEO_UTILS_H
