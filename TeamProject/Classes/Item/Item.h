//
//  Item.h
//  TeamProject
//
//  Created by NgocDu on 14/01/25.
//
//

#ifndef TeamProject_Item_h
#define TeamProject_Item_h

#include <iostream>
#include "cocos2d.h"
#include "Character.h"
#include "RMTiledMap.h"
using namespace cocos2d;
using namespace std;
class Item : public CCSprite
{
public:
    Item();
    ~Item();
//    void create(int type);
    void addToMap(CCPoint location, CCLayer* layer, RMTiledMap* tileMap);
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
   CC_SYNTHESIZE(CCPoint, _pointMap, PointMap);
   CC_SYNTHESIZE(string, _nameFile, NameFile);
};

#endif
