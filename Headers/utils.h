//
// Created by Usuari on 26/4/2023.
//


#ifndef XARXA_SOCIAL_UTILS_H
#define XARXA_SOCIAL_UTILS_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define INVALID_OPTION (-1)
#define OPTION_QUIT (0)
#define OPTION_NEW_USER (1)
#define OPTION_LIST_USERS (2)
#define OPTION_OPERATE_USER (3)

#define OPTION_REQUEST (1)
#define OPTION_MANAGE (2)
#define OPTION_POST (3)
#define OPTION_LIST_POSTS (4)
#define OPTION_RETURN_MENU (0)

void flush_input();
int read_int(const char* message);

#endif //XARXA_SOCIAL_UTILS_H
