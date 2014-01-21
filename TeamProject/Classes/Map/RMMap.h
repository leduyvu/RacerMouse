//
//  RMMap.h
//  TeamProject
//
//  Created by Vinh Nhon on 9/01/14.
//
//

#ifndef __TeamProject__RMMap__
#define __TeamProject__RMMap__

#include <iostream>
#include "cocos2d.h"
#include "CCJSONData.h"
#include "CCJSONConverter.h"

using namespace cocos2d;

class RMMap : public cocos2d::CCLayer
{
private:
    CCDictionary* mapInfo;
    CCArray* matrixInfo;
    CCArray* charactersInfo;
    CCSpriteBatchNode* gameBatchNode;
    
public:
    RMMap();
    ~RMMap();
    virtual bool init();
    CREATE_FUNC(RMMap);
    void testCreateMap();
    void testLoadMap();
    void testDraw();
};
#endif /* defined(__TeamProject__RMMap__) */
