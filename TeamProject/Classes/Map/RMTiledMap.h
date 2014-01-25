//
//  RMTiledMap.h
//  TeamProject
//
//  Created by Vinh Nhon on 20/01/14.
//
//

#ifndef __TeamProject__RMTiledMap__
#define __TeamProject__RMTiledMap__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;

class RMTiledMap : public cocos2d::CCLayer
{
private:
    CCTMXTiledMap* tileMap;
    CCTMXLayer *meta;
    int checkPush;
public:
    virtual bool init();
    CREATE_FUNC(RMTiledMap);
    CCTMXLayer* getMetaLayer();
    CCTMXTiledMap* getTiledMap();
    CCPoint tileCoordForPosition(CCPoint position);
    CCString* typeAtTileCoord(CCPoint tileCoord);
    CCPoint convertPosMapToPoint(CCPoint posMap);
};

#endif /* defined(__TeamProject__RMTiledMap__) */
