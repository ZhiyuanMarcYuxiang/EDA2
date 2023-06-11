//
// Created by Usuari on 28/5/2023.
//

#ifndef XARXA_SOCIAL_34_LIST_POSTS_H
#define XARXA_SOCIAL_34_LIST_POSTS_H

#include "search_utils.h"

#define FRIEND (1)

void listPosts (User *user, int who);

void listfriendPosts (Network* net, User *operating_user);

void listFriends(User* operating_user);
#endif //XARXA_SOCIAL_34_LIST_POSTS_H
