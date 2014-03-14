//
//  Client.h
//  TeamProject
//
//  Created by macbook_006 on 3/10/14.
//
//

#ifndef __TeamProject__Client__
#define __TeamProject__Client__

#include <iostream>
#include "ClientSocket.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "cocos2d.h"
class Client{
private:
    ClientSocket* clientSocket;
    CC_SYNTHESIZE(int, clientID, ClientID);
    CC_SYNTHESIZE(Package*, package, Package);

public:
    Client(ClientSocket* sock);
    ~Client();
    bool login();
    bool connectRoom(int roomID);
    bool quitRoom();
    bool exitGame();
    void setSocket(ClientSocket* sock);
    ClientSocket* getSocket();
    
};
#endif /* defined(__TeamProject__Client__) */
