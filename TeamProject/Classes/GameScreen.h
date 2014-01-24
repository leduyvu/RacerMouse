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
#include <stdlib.h>     /* srand, rand */
#include <time.h>
class GameScreen : public cocos2d::CCLayer
{
private:
    Character* player;
//    Character* cat;
    RMTiledMap *tiledMap;
    CCTMXLayer* meta;
    CCArray* arrCharacters;
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
    void autoPlay();
};

#endif /* defined(__TeamProject__GameScreen__) */
