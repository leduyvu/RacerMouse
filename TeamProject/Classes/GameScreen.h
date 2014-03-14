//
//  GameScreen.h
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#ifndef __TeamProject__GameScreen__
#define __TeamProject__GameScreen__

#include <iostream>
#include "cocos2d.h"
#include "Character.h"
#include "Cat.h"
#include "Dog.h"
#include "Map/RMMap.h"
#include "RMTiledMap.h"
#include "Player.h"
#include "Item/ItemObject.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Client.h"
#include "GameMenu.h"
class GameScreen : public cocos2d::CCLayer
{
private:
    Client* client;
    Package* package;
    ClientSocket* clientSock;
    
    
    Character* player;
    Character* cat;
    RMTiledMap *tiledMap;
    CCTMXLayer* meta;
    CCArray* arrCharacters;
    CCArray *_arrItems;
    CCArray *_arrItemsRemove;
    CCArray* arrPlayers;
    CCArray* arrItems;
    CCSize size;
    CCSprite *_pauseLayer;
    CCSprite *_ice;
    CCSprite *_invi;
    CCSprite *_speed;
    CCSprite *_streng;

    int countKey;
    bool isSlow;
    int timeSlow;
    float iceTime = 0;
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    ~GameScreen();
    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    //map
    void initMap();
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameScreen);
    bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    void ccTouchEnded(CCTouch *touch, CCEvent *event);
    void registerWithTouchDispatcher();
    
    //automation
    void autoCharactersPlay();
    void autoPlay();
    void autoImpactItem();
    /************************** ITEM ***********************/
    //slow after eat item
    void slowCharacters(bool bICE);
    void normalCharacters();
    void itemICE();
    void impactWithPlayer(CCArray* arrPlayer, CCArray* arrItems);
    void increaseVelocityPlayer();
    void invisibility();
    void chivy(int type);
    void iceCount();
    void transformPlayer(Player* player);
    /*********************** end Item ***********************/
    
    void eatKey(Character* player);
    void update(float dt);
    void onMenu(CCObject * pSender);
    void onContinue(CCObject * pSender);
    void onRestart(CCObject * pSender);
    void onQuit(CCObject * pSender);
 };

#endif /* defined(__TeamProject__GameScreen__) */
