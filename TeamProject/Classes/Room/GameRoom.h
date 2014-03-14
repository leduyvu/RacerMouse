//
//  RoomScene.h
//  TeamProject
//
//  Created by macbook_006 on 3/10/14.
//
//

#ifndef __TeamProject__GameRoom__
#define __TeamProject__GameRoom__

#include <iostream>
#include "cocos2d.h"
//#include "GameScreen.h"
#include "ClientSocket.h"
#include "Definition.h"
#include "Client.h"
#include "WaittingScene.h"
USING_NS_CC;
class GameRoom : public cocos2d::CCLayer
{
public:
//    bool touchExist;
    virtual bool init();
    static cocos2d::CCScene* scene();
    CREATE_FUNC(GameRoom);
    ~GameRoom();
//    void initMapsData();
//    void menuNewGameCallback();
//    void listMap(CCNode* sender);
//    
//    void quit();
//    //sound
//    void settingContentBGM();
//    void settingBMG(CCNode* sender, void *data);
//    void settingSound();
    //connect server
    void connectServer();
    void connectRoom();
private:
    Client *client;
    int level;
    //sound
    CCLayer *musicContainer;
    bool isSetMusicOn;
    bool holdingBGMThumb;
    ClientSocket* socket;
    
};
#endif /* defined(__TeamProject__RoomScene__) */
