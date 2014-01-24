//
//  Character.h
//  TeamProject
//
//  Created by macbook_006 on 1/6/14.
//
//

#ifndef __TeamProject__Character__
#define __TeamProject__Character__

#include <iostream>
#include "cocos2d.h"
#include "Definition.h"
#include "RMTiledMap.h"
USING_NS_CC;
class Character : public CCObject{
protected:
    CC_SYNTHESIZE(CCSprite*, spr, Sprite);
private:
    int objectID;
    CC_SYNTHESIZE(CCPoint, position, Position);
    int direction;
//    float timeVelocity;
    CC_SYNTHESIZE(float, timeVelocity, Velocity);
    CC_SYNTHESIZE(int, runValue, RunValue);
    CC_SYNTHESIZE(int, runCurrent, RunCurrent);
//    RMTiledMap *tiledMap;
public:
    Character();
    ~Character();
    virtual void create();
    void addToMap(CCPoint location, CCLayer* layer, RMTiledMap* tileMap);
    
    bool checkLeft(RMTiledMap *tiledMap, CCPoint currenPos);
    bool checkRight(RMTiledMap *tiledMap, CCPoint currenPos);
    bool checkBelow(RMTiledMap *tiledMap, CCPoint currenPos);
    bool checkUpward(RMTiledMap *tiledMap, CCPoint currenPos);

    void moveLeft(RMTiledMap *tiledMap);
    void moveRight(RMTiledMap *tiledMap);
    void moveBelow(RMTiledMap *tiledMap);
    void moveUpward(RMTiledMap *tiledMap);
    
    virtual void autoRun(RMTiledMap* tileMap);
};
#endif /* defined(__TeamProject__Character__) */
