//
//  WaittingScene.h
//  TeamProject
//
//  Created by macbook_006 on 3/11/14.
//
//

#ifndef __TeamProject__WaittingScene__
#define __TeamProject__WaittingScene__

#include <iostream>
#include "cocos2d.h"
#include "GameScreen.h"
#include "ClientSocket.h"
#include "Definition.h"
#include "Client.h"
USING_NS_CC;
class WaittingScene : public cocos2d::CCLayer
{
public:
    //    bool touchExist;
    virtual bool init(Client* client);
    static cocos2d::CCScene* scene(Client* client);
    static WaittingScene* create(Client* client);
    ~WaittingScene();
    void ready();
    void update();
    void quitRoom();
private:
    Client *client;
};

#endif /* defined(__TeamProject__WaittingScene__) */
