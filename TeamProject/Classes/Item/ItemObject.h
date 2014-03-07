//
//  Item.h
//  TeamProject
//
//  Created by NgocDu on 14/01/25.
//
//

#ifndef TeamProject_ItemObject_h
#define TeamProject_ItemObject_h

#include <iostream>
#include "cocos2d.h"
#include "RMTiledMap.h"
#include "Definition.h"
using namespace cocos2d;
using namespace std;
class ItemObject : public CCObject
{
public:
    ItemObject();
    ~ItemObject();
    void create(int type);
    void addToMap(CCPoint location, CCLayer* layer, RMTiledMap* tileMap);
    void deleteItem(CCLayer* layer);
private:
    /*
     1 - biến hình
     2 - tàng hình
     3 - tăng tốc
     4 - xuyên tường
     5 - đặt bẫy
     6 - SlowSpeed
     7 - đóng băng
     8 - bóng đèn
     9 - xua đuổi
     */
    CC_SYNTHESIZE(int, _type, Type);
    CC_SYNTHESIZE(CCPoint, _pointMap, Location);
    CC_SYNTHESIZE(CCSprite*, spr, Sprite);
};

#endif
