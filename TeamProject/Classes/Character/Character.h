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
USING_NS_CC;
class Character : public CCObject{
protected:
    CCSprite* spr;
private:
    int objectID;
    CCPoint position;
    int direction;
    int velocity;
public:
    Character();
    ~Character();
    virtual void create();
    void addToMap(CCPoint location, CCLayer* layer);
};
#endif /* defined(__TeamProject__Character__) */
