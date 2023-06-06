//
// Created by Usuari on 28/5/2023.
//

#ifndef XARXA_SOCIAL_31_SEND_REQUEST_H
#define XARXA_SOCIAL_31_SEND_REQUEST_H

#include "32.manage_requests.h"

void sendRequest (Network *net);
void printFriendRequests(User* user);
void sendFriendRequest(Network* net, User *operating_user);

#endif //XARXA_SOCIAL_31_SEND_REQUEST_H
